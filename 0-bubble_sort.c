#include "sort.h"
/**
 * bubble_sort - sort array lements from min to max value
 * @array: array
 * @no_element: array no_element
 */
void bubble_sort(int *array, size_t no_element)
{

	size_t i, index, tmp = 0;

	if (no_element < 2)
		return;
	for (i = 0; i < no_element; i++)
		for (index = 0; index < no_element; index++)
		{
			if (array[index] > array[index + 1] && array[index + 1])
			{
			tmp = array[index];
			array[index] = array[index + 1];
			array[index + 1] = tmp;
			print_array(array, no_element);
			}
		}
}
