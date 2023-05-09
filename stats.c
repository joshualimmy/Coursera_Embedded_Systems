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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)



void print_array(unsigned char test[], int i){
     printf("Array for print_array contains: ");
     for(i = 0; i < 40; i++)
         printf("%d ", test[i]);
         printf("\n ");
     return;
     }


void sort_array(unsigned char test[], int i, int len){
    int temp = 0;
    int j;
				    				   
    for(j = 0; j < 40; j++){
      for(i = 0; i < 39; i++){
         if(test[i] < test[i+1]){
	   temp = test[i];    
	   test[i] = test[i+1];    
	   test[i+1] = temp;    
	 }
      }
    }
     printf("\nArray for sort_array contains: ");     
     for(i = 0; i < 40; i++)
        printf("%d ", test[i]);
        printf("\n ");
    return;
}


void find_maximum(unsigned char test[], int i, int len){
    int temp = 0;
    int j;
				    				    
    for(j = 0; j < 40; j++){
      for(i = 0; i < 39; i++){
         if(test[i] < test[i+1]){
	   temp = test[i];    
	   test[i] = test[i+1];    
	   test[i+1] = temp;    
	 }
      }
    }
        printf("\nMaximum for the array for find_maximum is: %d", test[0]); 
        printf("\n ");
    return;
}


void find_minimum(unsigned char test[], int i, int len){
    int temp = 0;
    int j;
				    				    
    for(j = 0; j < 40; j++){
      for(i = 0; i < 39; i++){
         if(test[i] < test[i+1]){
	   temp = test[i];    
	   test[i] = test[i+1];    
	   test[i+1] = temp;    
	 }
      }
    }
    printf("\nMinimum for the array for find_minimum is: %d", test[len-1]); 
    printf("\n ");
    return;
}

void find_mean(unsigned char test[], int i, int len){
    //int temp = 0;
    //int j;
    int sum = 0;
    int mean = 0;
    int median = 0;

    for(i = 0; i < 40; i++){
       sum = sum + test[i];			    
    }
    mean = sum / i;
    printf("\nMean for find_mean (rounded to nearest whole number) is: %d", mean);
				    				    
    return;
}


void find_median(unsigned char test[], int i, int len){
    //int temp = 0;
    //int j;
    //int sum = 0;
    //int mean = 0;
    int median = 0;

    if(len%2 == 0)
      median = (test[len/2] + test[(len/2) + 1]) / 2;
    else
      median = test[len/2 + 1];
                                        
    printf("\nMedian for find_median (rounded to nearest whole number) is: %d\n", median);

				    				    
    return;
}


void print_statistics(unsigned char test[], int i, int len){

   printf("\nPrint statistics start-----------");
   find_maximum(test, 40, len);
   find_minimum(test, 40, len);     
   find_mean(test, 40, len);
   find_median(test, 40, len);
   printf("Print statistics end-------------\n");

}

				    
				    
void main() {
  int len = 40;

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

   print_array(test, 40);
   sort_array(test, 40, len);
   find_maximum(test, 40, len);
   find_minimum(test, 40, len);     
   find_mean(test, 40, len);
   find_median(test, 40, len);
   print_statistics(test, 40, len);
   //return 0;







  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}

/* Add other Implementation File Code Here */











