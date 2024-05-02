#include "sort.h"


void merge(int *array, int *left, size_t
size_left, int *right, size_t size_right)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);

	while (i < size_left && j < size_right)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < size_left)
		array[k++] = left[i++];

	while (j < size_right)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, size_left + size_right);
}
/**
 * merge_sort - function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @array: array
 * @size: size of the array
 * Return: void
*/
void merge_sort(int *array, size_t size)
{
	size_t mid, i;
	int *left, *right;

	if (size < 2)
		return;

	mid = size / 2;

	left = malloc(sizeof(int) * mid);
	right = malloc(sizeof(int) * (size - mid));

	for (i = 0; i < mid; i++)
		left[i] = array[i];

	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, mid, right, size - mid);

	free(left);
	free(right);
}
