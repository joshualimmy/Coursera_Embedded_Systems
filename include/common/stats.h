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
 * @file stats.h
 * @brief Header file for manipulation and printing stats of an array
 *
 * This file contains the headers required for the c1m1 assignment
 *
 * @author Joshua Lim
 * @date 08/05/2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__




/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Prints the statistics of the array 
 *
 * This function prints the contents of an array
 *
 * @param array The pointer to the array
 *
 * @return void
 */
void print_array(unsigned char *array , int i);

/**
 * @brief Sorts the contents of the array from largest to smallest
 *
 * This function sorts the contents of the array from largest to smallest
 *
 * @param array The pointer to the array
 * @param temp  A temporary variable
 *
 * @return void
 */
void sort_array(unsigned char *array, int i);

/**
 * @brief Finds the maximum value out of all elements in the array
 *
 * This function finds the maximum value out of all elements in the array
 *
 * @param array The pointer to the array
 * @param maximum The maximum value of the array, which is array[0] 
 *
 * @return maximum
 */
unsigned char find_maximum(unsigned char *array, int i);

/**
 * @brief Finds the minimum value out of all elements in the array
 *
 * This function finds the minimum value out of all elements in the array
 *
 * @param array The pointer to the array
 * @param maximum The maximum value of the array, which is array[SIZE-1] 
 *
 * @return minimum
 */
unsigned char find_minimum(unsigned char *array, int i);


/**
 * @brief Finds the mean value out of all elements in the array
 *
 * This function finds the mean value out of all elements in the array
 *
 * @param array The pointer to the array
 * @param mean The mean value of the array 
 *
 * @return mean
 */
unsigned char find_mean(unsigned char *array, int i);

/**
 * @brief Finds the median value out of all elements in the array
 *
 * This function finds the median value out of all elements in the array
 *
 * @param array The pointer to the array
 * @param median The median value of the array 
 *
 * @return median
 */
unsigned char find_median(unsigned char *array, int i);

/**
 * @brief Prints statistics for elements in the array
 *
 * This function prints all the statistics for elements in the array, including maximum, minimum, mean and median
 *
 * @param array The pointer to the array
 * @param maximum The maximum value of the array
 * @param minimum The minimum value of the array
 * @param mean The mean value of the array
 * @param median The median value of the array
 *
 * @return void
 */
void print_statistics(unsigned char *array, int i);
#endif /* __STATS_H__ */
