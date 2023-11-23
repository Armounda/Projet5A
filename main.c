/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.h"
#include "hal.h"
#include "rt_test_root.h"
#include "oslib_test_root.h"
#include "chprintf.h"
#include "string.h"

/*
 * Green LED blinker thread, times are in milliseconds.
 */
int counter = 0;

//default blinker thread
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {

  (void)arg;
  chRegSetThreadName("blinker");
  while (true) {
    palClearPad(GPIOA, GPIOA_LED_GREEN);
    chThdSleepMilliseconds(500);
    palSetPad(GPIOA, GPIOA_LED_GREEN);
    chThdSleepMilliseconds(500);
  }
}

//hello world thread
static THD_WORKING_AREA(waHELLO1, 128);
static THD_FUNCTION(HELLO1, arg){

  (void)arg;
  chRegSetThreadName("Hello1");
  while(true){
    //sdWrite(&SD2, (uint8_t*)"Hello World", 11);

    //chprintf((BaseSequentialStream *)&SD2, "TEST = %d\n\r", counter);
    counter++;
    chThdSleepMilliseconds(500);
  }
}

//Serial Tx thread
static THD_WORKING_AREA(waTxSerial, 128);
static THD_FUNCTION(TxSerial, arg){
  (void)arg;
  chRegSetThreadName("TxSerial");
  while(true){
    //sdWrite(&SD6, (uint8_t*)"Hello World", 11);
    emmit("Hello World", 11);
    chThdSleepMilliseconds(1500);
  }
}
//Serial Rx thread
static THD_WORKING_AREA(waRxSerial,128);
static THD_FUNCTION(RxSerial, arg){
  (void)arg;
  chRegSetThreadName("rxSerial");
  while(true){
    //uint8_t token = sdGet(&SD6);
    char buffer[11];
    sdRead(&SD6, buffer, sizeof(buffer) - 1);
    chprintf((BaseSequentialStream *)&SD2, "reception was checked \n\r");
    chThdSleepMilliseconds(500);
  }
}

//serial communication functions
void emmit(char *msg, int size){
  sdWrite(&SD6, (uint8_t*)msg, size);
  chprintf((BaseSequentialStream *)&SD2, "item %s was sent \n\r",msg);
}
char* recieve(void) {
    char* buffer = chHeapAlloc(NULL, 12); // Allocate memory on the heap
    size_t bytesRead = sdRead(&SD6, buffer, 11);
    buffer[bytesRead] = '\0'; // Add a null terminator to make it a valid C string
    //chprintf((BaseSequentialStream *)&SD2, "reception was checked: %s\n\r", buffer);
    chThdSleepMilliseconds(500);
    return buffer;
}



/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /*
   * Activates the serial driver 2 using the driver default configuration.
   */
  //CONFIG PINS FOR SERIAL COM
  // Configuring PC6 as AF8 assigning it to USART6_TX.
  palSetPadMode(GPIOC, 6, PAL_MODE_ALTERNATE(8));
  // Configuring PC7 as AF8 assigning it to USART6_RX.
  palSetPadMode(GPIOC, 7, PAL_MODE_ALTERNATE(8));
  
  //starting the serial drivers
  sdStart(&SD2, NULL); //usb com
  sdStart(&SD6, NULL); //serial test

  //launchage de threads
  // Creates the blinker thread.
  //chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);
  // create the hello thread
  //chThdCreateStatic(waHELLO1, sizeof(waHELLO1), NORMALPRIO, HELLO1, NULL);
  // create the serial Tx thread
  chThdCreateStatic(waTxSerial, sizeof(waTxSerial), NORMALPRIO, TxSerial, NULL);
  // create the serial Rx thread
  //chThdCreateStatic(waRxSerial, sizeof(waRxSerial), NORMALPRIO, TxSerial, NULL);


  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (true) {
    if (!palReadPad(GPIOC, GPIOC_BUTTON)) {
      //test_execute((BaseSequentialStream *)&SD2, &rt_test_suite);
      //test_execute((BaseSequentialStream *)&SD2, &oslib_test_suite);
      chprintf((BaseSequentialStream *)&SD2, "HELLO WORLD\n\r");
    }
    char *test = recieve();
    chprintf((BaseSequentialStream *)&SD2, "this data was received in main : %s\n\r",test);
    chHeapFree(test); // Free the allocated memory
    chThdSleepMilliseconds(500);
  }
}
