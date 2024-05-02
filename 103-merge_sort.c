#include"sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;
	mergesort(array, 0, size - 1, size);
}
