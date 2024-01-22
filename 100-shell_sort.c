#include "sort.h"

/**
 * swap_ints - It swap two integers in an array.
 * @a: The first integer to be swap.
 * @b: The second integer to be swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - It sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of an integers.
 * @size: The size of the an array.
 *
 * Description: The team used gap to determine the gap or interval
 * between elements during the sorting process
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
