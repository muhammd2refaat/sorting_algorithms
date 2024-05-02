#include"sort.h"


/**
 * merge_sort - function that sorts an array of integers in ascending
 * order using the Merge sort algorithm
 * @array: array
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *left, *right, *result, i, j, k;

	if (size < 2)
		return;
	left = malloc(sizeof(int) * (size / 2));
	right = malloc(sizeof(int) * (size - size / 2));
	result = malloc(sizeof(int) * size);
	for (i = 0; i < size / 2; i++)
		left[i] = array[i];
	for (j = 0; j < size - size / 2; j++)
		right[j] = array[size / 2 + j];
	merge_sort(left, size / 2);
	merge_sort(right, size - size / 2);
	i = j = 0;
	k = 0;
	while (i < size / 2 && j < size - size / 2)
	{
		if (left[i] <= right[j])
		{
			result[k++] = left[i++];
		}
		else
		{
			result[k++] = right[j++];
		}
	}
	while (i < size / 2)
		result[k++] = left[i++];
	while (j < size - size / 2)
		result[k++] = right[j++];
	for (i = 0; i < size; i++)
		array[i] = result[i];
	free(left);
	free(right);
	free(result);
}

