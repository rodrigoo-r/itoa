#ifndef ITOA_LIBRARY_H
#define ITOA_LIBRARY_H

/**
 * Converts a long integer value to a dynamically allocated string.
 *
 * @param value The long integer value to convert.
 * @return A pointer to the dynamically allocated string representing the number,
 *         or NULL if memory allocation fails.
 *
 * The caller is responsible for freeing the allocated memory.
 * Handles both positive and negative numbers, as well as the edge case of 0.
 */
char *itoa(long value);

#endif //ITOA_LIBRARY_H