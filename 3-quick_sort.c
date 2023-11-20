#include "sort.h"
/**
*swap - the positions of two elements into an array
*@array: array
*@quantity1: array element
*@quantity2: array element
*/
void swap(int *array, ssize_t quantity1, ssize_t quantity2)
{
	int tmp;

	tmp = array[quantity1];
	array[quantity1] = array[quantity2];
	array[quantity2] = tmp;
}
/**
 *lomuto_partition - lomuto partition sorting scheme implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@no_element: no_element array
 *Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t no_element)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, no_element);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, no_element);
	}
	return (current);
}
/**
 *qs - qucksort algorithm implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@no_element: array no_element
 */
void qs(int *array, ssize_t first, ssize_t last, int no_element)
{
	ssize_t position = 0;


	if (first < last)
	{
		position = lomuto_partition(array, first, last, no_element);

		qs(array, first, position - 1, no_element);
		qs(array, position + 1, last, no_element);
	}
}
/**
 *quick_sort - prepare the terrain to quicksort algorithm
 *@array: array
 *@no_element: array no_element
 */
void quick_sort(int *array, size_t no_element)
{
	if (!array || no_element < 2)
		return;
	qs(array, 0, no_element - 1, no_element);
}
