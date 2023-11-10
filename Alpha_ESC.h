/*
 * Alpha_ESC.h
 *
 *  Created on: 9 nov. 2023
 *      Author: letoi
 */

#ifndef ALPHA_ESC_H_
#define ALPHA_ESC_H_

#define ALPHA_ESC_B1 = 0x9B  // byte 1 - header
#define ALPHA_ESC_B2 = 0x16  // byte 2 - packet size
#define ALPHA_ESC_PACKET_SIZE = 24  // 22 byte packet + 2 byte checksum
#define ALPHA_ESC_BAUD = 19200  // fixed baudrate
#define NB_POLES = 21


uint8_t temp_table[256] = {129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,127,128,127,125,126,123,122,123,124,123,120,121,120,118,119,117,117,115,116,115,113,114,113,112,110,111,110,109,107,108,107,106,106,105,104,104,103,101,102,101,100,99,98,98,97,96,96,96,95,94,93,93,92,91,91,90,90,89,88,88,87,86,87,87,85,85,84,83,83,82,82,81,81,80,80,79,79,78,78,77,77,76,75,75,75,74,74,73,73,72,72,71,71,70,70,69,69,68,68,67,67,66,66,66,65,65,64,64,63,63,62,62,61,61,61,60,60,59,59,58,58,58,57,57,56,56,55,55,54,54,53,53,53,52,52,51,51,50,50,50,49,49,48,48,47,47,46,46,45,45,44,44,44,43,43,42,42,41,41,40,40,39,39,38,38,37,37,36,36,35,35,34,34,33,33,32,32,31,30,30,29,29,28,28,27,26,26,25,25,24,23,23,22,21,21,20,19,19,18,17,16,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,0,0,0,0,0};

typedef struct AlphaTelemetry {
  uint8_t nbPoles;
  uint8_t buf_len;
  uint8_t rxbuf;
  uint16_t baleNumber;
  uint16_t rxThrottle;
  uint16_t outputThrottle;
  uint16_t rpm;
  uint16_t voltage;
  uint16_t busbarCurrent;
  uint16_t phaseWireCurrent;
  uint8_t mosfetTemp;
  uint8_t capacitorTemp;
  uint16_t statusCode;
  uint8_t fault;
  uint8_t ready;
}ALPHATELEMETRY;

#endif /* ALPHA_ESC_H_ */
