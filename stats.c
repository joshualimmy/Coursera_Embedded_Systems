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
 * @file stats.c 
 * @brief File that manipulates and prints stats of an array
 *
 * This file contains the functions requested for the c1m1 assignment
 *
 * @author Joshua Lim
 * @date 08/05/2023
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)



void print_array(unsigned char *array , int i){
     printf("Array for print_array contains: {");
     for(i = 0; i < SIZE; i++)
         printf("%d ", array[i]);
         printf("}\n ");

     sort_array(array, SIZE);

     printf("Array after sorting contains: {");
     for(i = 0; i < SIZE; i++)
         printf("%d ", array[i]);
         printf("}\n ");
     }

void sort_array(unsigned char *array, int i){
    int temp = 0;
    int j;
				    				   
    for(j = 0; j < SIZE; j++){
      for(i = 0; i < SIZE-1; i++){
         if(array[i] < array[i+1]){
	   temp = array[i];    
	   array[i] = array[i+1];    
	   array[i+1] = temp;    
	 }
      }
    }
}


unsigned char find_maximum(unsigned char *array, int i){
    unsigned char maximum = 0;

    sort_array(array, SIZE);
    //printf("\nMaximum for the array for find_maximum is: %d", array[0]); 
    //printf("\n ");
    maximum = array[0];
    return maximum;
}


unsigned char find_minimum(unsigned char *array, int i){
    int minimum = 0;

    //printf("\nMinimum for the array for find_minimum is: %d", array[SIZE-1]); 
    //printf("\n ");
    minimum = array[SIZE-1];
    return minimum;
}

unsigned char find_mean(unsigned char *array, int i){
    int sum = 0;
    int mean = 0;

    for(i = 0; i < SIZE; i++){
       sum = sum + array[i];			    
    }
    mean = sum / i;
    //printf("\nMean for find_mean (rounded to nearest whole number) is: %d", mean);				    				    
    return mean;
}


unsigned char find_median(unsigned char *array, int i){
    int median = 0;

    if(SIZE%2 == 0)
      median = (array[SIZE/2] + array[(SIZE/2) + 1]) / 2;
    else
      median = array[SIZE/2 + 1];                                    
    //printf("\nMedian for find_median (rounded to nearest whole number) is: %d\n", median);				    				    
    return median;
}


void print_statistics(unsigned char *array, int i){

   printf("\nPrint statistics start-----------");
    
   printf("\nMaximum for the array for find_maximum is: %d", find_maximum(array, SIZE)); 
   printf("\nMinimum for the array for find_minimum is: %d", find_minimum(array, SIZE)); 
   printf("\nMean for find_mean (rounded to nearest whole number) is: %d", find_mean(array, SIZE));
   printf("\nMedian for find_median (rounded to nearest whole number) is: %d\n", find_median(array, SIZE));
   printf("Print statistics end-------------\n");

}

				    
				    
void main() {
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  //unsigned char maximum, minimum, mean, median;
  /* Statistics and Printing Functions Go Here */
   print_array(test, SIZE);
   sort_array(test, SIZE);
   find_maximum(test, SIZE);
   find_minimum(test, SIZE);     
   find_mean(test, SIZE);
   find_median(test, SIZE);
   print_statistics(test, SIZE);
   //return 0;





}

/* Add other Implementation File Code Here */











