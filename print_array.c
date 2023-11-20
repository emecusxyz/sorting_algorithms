#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @no_element: Number of elements in @array
 */
void print_array(const int *array, size_t no_element)
{
    size_t i;

    i = 0;
    while (array && i < no_element)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
