/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"
#include <stdio.h>

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8 * my_memmove(uint8_t * src, uint8_t * dst, uint8 length){
    int i;
    for(i = 0; i < length; i++){
        *dst = 0;
	*dst = *src;
	src++;
	dst++;
    }
    return dst;
}


uint8 * my_memcopy(uint8_t * src, uint8_t * dst, uint8 length){
    int i;
    for(i = 0; i < length; i++){
        *dst = *src;
	src++;
	dst++; 
    }
    return dst;
}

uint8 * my_memset(uint8_t * src, uint8_t length, uint8 value){
    int i;
    for(i = 0; i < length; i++){
	*src = value;
    }
    return src;
}

uint8 * my_memzero(uint8_t * src, uint8 length){
    int i;
    for(i = 0; i < length; i++){
         *src = 0;
    }
    return src;
}

uint8 * my_reverse(uint8_t * src, uint8 length){
    uint8 temp = 0;
    int i;
    uint8 *start_src, *end_src;

    start_src = src;
    end_src = src + (length - 1);

    for(i = 0; i < (length-1)/2; i++){
        temp = *start_src;
	*start_src = *end_src;
	*end_src = temp;
        start_src++;
        end_src--;
    }
    return src;
}

int32 * reserve_words(uint8 length){
    int32 *addr;
    if (((int32 *) malloc(length)) == NULL)
        return NULL;
    else{
	addr = ((int32 *) malloc(length));    
	return
	}	
}

void free_words(int32_t * src){
	    free((void *)src);
}

























