/**
 * @brief Converts data from integer to ASCII string
 *
 * Converts data from integer to ASCII string using pointer arithmetic, not array indexing
 *
 * @param data The int number to be converted
 * @param ptr Pointer to data array
 * @param base Base to convert to
 *
 * @return length of the converted data.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts given data from ASCII string to integer
 *
 * Converts data from ASCII string to integer using pointer arithmetic, not array indexing
 *
 * @param ptr Pointer to the string to be converted
 * @param digits Number of digits in the character set
 * @param value Base to convert to
 *
 * @return the converted integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

