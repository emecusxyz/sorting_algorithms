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
 *hoare_partition - hoare partition sorting scheme implementation
 *@array: array
 *@begin: begin array element
 *@end: end array element
 *@no_element: no_element array
 *Return: return the position of the end element sorted
 */
int hoare_partition(int *array, int begin, int end, int no_element)
{
	int current = begin - 1, finder = end + 1;
	int pivot = array[end];

	while (1)
	{

		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		swap(array, current, finder);
		print_array(array, no_element);
	}
}
/**
 *qs - qucksort algorithm implementation
 *@array: array
 *@begin: begin array element
 *@end: end array element
 *@no_element: array no_element
 */
void qs(int *array, ssize_t begin, ssize_t end, int no_element)
{
	ssize_t position = 0;

	if (begin < end)
	{
		position = hoare_partition(array, begin, end, no_element);
		qs(array, begin, position - 1, no_element);
		qs(array, position, end, no_element);
	}
}
/**
 *quick_sort_hoare - prepare the terrain to quicksort algorithm
 *@array: array
 *@no_element: array no_element
 */
void quick_sort_hoare(int *array, size_t no_element)
{
	if (!array || no_element < 2)
		return;
	qs(array, 0, no_element - 1, no_element);
}
