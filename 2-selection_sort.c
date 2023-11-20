#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @no_element: no_element of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t no_element)
{
	size_t i, index;
	int tmp, swap, flag = 0;

	if (array == NULL)
		return;
	for (i = 0; i < no_element; i++)
	{
		tmp = i;
		flag = 0;
		for (index = i + 1; index < no_element; index++)
		{
			if (array[tmp] > array[index])
			{
				tmp = index;
				flag += 1;
			}
		}
		swap = array[i];
		array[i] = array[tmp];
		array[tmp] = swap;
		if (flag != 0)
			print_array(array, no_element);
	}
}
