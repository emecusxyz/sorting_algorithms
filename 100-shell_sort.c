#include "sort.h"

/**
*swap - the positions of two elements into an array
*@array: array
*@quantity1: array element
*@quantity2: array element
*/
void swap(int *array, int quantity1, int quantity2)
{

	int tmp;

	tmp = array[quantity1];
	array[quantity1] = array[quantity2];
	array[quantity2] = tmp;
}
/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @no_element: no_element of the array
 * @array: list with numbers
 */
void shell_sort(int *array, size_t no_element)
{
	size_t gap = 1, i, index = 0;

	if (array == NULL || no_element < 2)
		return;
	while (gap < no_element / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < no_element; i++)
			for (index = i; index >= gap &&
			 (array[index] < array[index - gap]); index -= gap)
				swap(array, index, index - gap);
		print_array(array, no_element);
		gap /= 3;
	}
}
