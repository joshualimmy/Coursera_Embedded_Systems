/******************************************************************************
 *
 *
 *
 *
 ******************************************************************************/
 /* 
 * @file data.c
 * @brief Contains functions to be utilised by memory.c
 *
 * This file contains 2 functions
 * my_itoa takes input data as an integer and converts it to an ASCII string
 * my_atoi does the opposite and takes an ASCII string and converts it to integer 
 *
 * Additional notes: ASCII character for NULL is '\0'
 *                   ASCII conversion for int to string makes use of ASCII value of '0', which is 48
 *
 * @author Joshua Lim
 * @date 28/5/2023
 *
 *
 *
 *
/******************************************************************************
 *Function Definitions
*****************************************************************************/


#include <stdint.h>



uint8_t my_itoa(int32 data, uint8_t * ptr, uint32 base){

  uint8_t asciiString[i];
  int negative = 0;
  int i = 0;

  if (data < 0){
    negative = 1;  
  }
  
  //Main loop to convert data
  while (*ptr != NULL){
    asciiString[i] = (data % base) + '0';  
    i++;
    ptr++;
  }
  
  //Adding a '-' char if value is negative
  if (negative == 1){
    asciiString[i] = '-';  
  }
  //Adding a null char at the end
  asciiString[i] = '\0';

  //Reverse the string because values are being fed into the asciiString array in reverse order
  myReverse(*ptr, asciiString);

  return asciiString;
}


int32 my_atoi(uint8_t * ptr, uint8_t digits, uint32 base){

  int32 dataOut = 0;
  int negative = 0;

  if (*ptr == '-'){
    negative = 1;  
  }
  
  //Main loop to convert string
  while (*ptr != NULL){
    //incoming digit is multiplied by base to get an integer value, then 48 which is the value of '0' in ascii table is subtracted away
    digits = (digits * base) - 48;
    //the digits is then added together to get dataOut
    dataOut = dataOut + digits;
    ptr++ 
  }
  
  if (negative == 1){
    dataOut = -dataOut;  
  }

  return dataOut;
}




