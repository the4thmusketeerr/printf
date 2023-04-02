#include "main.h"

/**
 * calculate_size - Calculates the size of the argument to be casted
 * @format: The formatted string in which to print the arguments
 * @index: The current index of the character in the format string
 *
 * Return: The size of the argument to be casted
 */
int calculate_size(const char *format, int *index)
{
    int curr_index = *index + 1;
    int size = 0;

    if (format[curr_index] == 'l')
        size = ARG_LONG;
    else if (format[curr_index] == 'h')
        size = ARG_SHORT;

    if (size == 0)
        *index = curr_index - 1;
    else
        *index = curr_index;

    return size;
}
