/*
* This code is distributed under the terms of the GNU General Public License.
 * For more information, please refer to the LICENSE file in the root directory.
 * -------------------------------------------------
 * Copyright (C) 2025 Rodrigo R.
 * This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
 * This is free software, and you are welcome to redistribute it
 * under certain conditions; type `show c' for details.
*/

#ifndef FLUENT_LIBC_ITOA_LIBRARY_H
#define FLUENT_LIBC_ITOA_LIBRARY_H

#if defined(__cplusplus)
extern "C"
{
#endif

#include <stdlib.h>

#ifndef FLUENT_LIBC_RELEASE
#   include <std_bool.h> // fluent_libc
#else
#   include <fluent/std_bool/std_bool.h> // fluent_libc
#endif

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
static inline char *itoa_convert(long value)
{
    // Edge case: when the value is 0
    if (value == 0)
    {
        // Directly malloc the string
        char *str = (char *) malloc(sizeof(char) * 2);

        // Check for memory allocation failure
        if (str == NULL)
        {
            return NULL;
        }

        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    long chars = 0;
    int is_negative = FALSE;

    // Negate the number if needed
    if (value < 0)
    {
        value = -value;
        is_negative = TRUE;
    }

    // Calculate the number of characters we are going to need
    long value_clone = value;
    while (value_clone > 0)
    {
        // Increment the count
        chars++;
        // Decrement the number
        value_clone = value_clone / 10;
    }

    // Add 1 if the number is negative
    if (is_negative)
    {
        chars++;
    }

    // Allocate the string (+1 for the null terminator)
    char *str = (char *) malloc(sizeof(char) * (chars + 2));

    // Check for memory allocation failure
    if (str == NULL)
    {
        return NULL;
    }

    // Add a null terminator
    str[chars] = '\0';

    // Position the index accordingly
    long index = chars - 1;

    // Put character by character in the buffer
    while (value > 0)
    {
        // Get the digit
        const long digit = value % 10;

        // Put the character
        str[index] = (char)('0' + digit);
        index--;

        // Decrement the number
        value = value / 10;
    }

    // Add a negative sign
    if (is_negative)
    {
        str[0] = '-';
    }

    return str;
}

#if defined(__cplusplus)
}
#endif

#endif //FLUENT_LIBC_ITOA_LIBRARY_H