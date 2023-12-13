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
//custom includes for cube IA
#include "Middlewares/ST/AI/Inc/ai_datatypes_defines.h"
#include "Middlewares/ST/AI/Inc/ai_platform.h"
#include "X-CUBE-AI/App/sinus_network.h"
#include "X-CUBE-AI/App/sinus_network_data.h"

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

  // IA MANAGMENT

  // declares the variables that will be used
  char buffer[50];
  int buff_len = 0;
  ai_error ai_err;
  ai_i32 nbatch;
  uint32_t timestamp;
  float y_val;

  // chunk of memory used to hold intermediate values for neural network
  AI_ALIGNED(4) ai_u8 activations[AI_SINUS_NETWORK_DATA_ACTIVATIONS_SIZE];

  //buffers to store inputs and outputs tensors
  AI_ALIGNED(4) ai_u8 in_data[AI_SINUS_NETWORK_IN_1_SIZE_BYTES];
  AI_ALIGNED(4) ai_u8 out_data[AI_SINUS_NETWORK_OUT_1_SIZE_BYTES];

  //pointer to the model
  ai_handle sinus_network_model = AI_HANDLE_NULL;

  //init the wrapper structs that hold the pointers to data and info about the
  //data (tensot height, width, channels)
  //ai_buffer ai_input[AI_SINUS_NETWORK_IN_NUM] = AI_SINUS_NETWORK_IN;
  //ai_buffer ai_output[AI_SINUS_NETWORK_OUT_NUM] = AI_SINUS_NETWORK_OUT;
  /*
   * Activates the serial driver 2 using the driver default configuration.
   */
  sdStart(&SD2, NULL);

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (true) {
    if (!palReadPad(GPIOC, GPIOC_BUTTON)) {
      test_execute((BaseSequentialStream *)&SD2, &rt_test_suite);
      test_execute((BaseSequentialStream *)&SD2, &oslib_test_suite);
    }
    chThdSleepMilliseconds(500);
  }
}
