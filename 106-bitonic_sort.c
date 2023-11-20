#include "sort.h"
#include <stdio.h>
/**
 * swap - change two values in ascending or descending order
 * @arr: array
 * @quantity1: item one
 * @quantity2: item two
 * @order: 1: ascending order, 0 descending order
 */
void swap(int arr[], int quantity1, int quantity2, int order)
{
	int temp;

	if (order == (arr[quantity1] > arr[quantity2]))
	{
		temp = arr[quantity1];
		arr[quantity1] = arr[quantity2];
		arr[quantity2] = temp;
	}
}
/**
 * merge - sort bitonic sequences recursively in both orders
 * @arr: array
 * @low: first element
 * @nelemnt: elements number
 * @order: 1: ascending order, 0 descending order
 */
void merge(int arr[], int low, int nelemnt, int order)
{
	int mid, i;

	if (nelemnt > 1)
	{
		mid = nelemnt / 2;
		for (i = low; i < low + mid; i++)
			swap(arr, i, i + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}
/**
 * bitonicsort - bitonic sort algorithm implementation
 * @arr: array
 * @low: first element
 * @nelemnt: number of elements
 * @order: 1: ascending order, 0 descending order
 * @no_element: array lenght
 */
void bitonicsort(int arr[], int low, int nelemnt, int order, int no_element)
{
	int mid;

	if (nelemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, no_element);
			print_array(&arr[low], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, no_element);
			print_array(&arr[low], nelemnt);
		}
		mid = nelemnt / 2;
		bitonicsort(arr, low, mid, 1, no_element);
		bitonicsort(arr, low + mid, mid, 0, no_element);
		merge(arr, low, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, no_element);
			print_array(&arr[low], nelemnt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, no_element);
			print_array(&arr[low], nelemnt);
		}
	}
}
/**
 * bitonic_sort - prepare the terrain to bitonic sort algorithm
 * @array: array
 * @no_element: array lenght
 */
void bitonic_sort(int *array, size_t no_element)
{
	int order = 1;

	if (!array || no_element < 2)
		return;
	bitonicsort(array, 0, no_element, order, no_element);
}
