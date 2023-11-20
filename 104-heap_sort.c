#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t no_element, size_t base, size_t root);
void heap_sort(int *array, size_t no_element);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @no_element: The no_element of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t no_element, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, no_element);
		max_heapify(array, no_element, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @no_element: The no_element of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t no_element)
{
	int i;

	if (array == NULL || no_element < 2)
		return;

	for (i = (no_element / 2) - 1; i >= 0; i--)
		max_heapify(array, no_element, no_element, i);

	for (i = no_element - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, no_element);
		max_heapify(array, no_element, i, 0);
	}
}
