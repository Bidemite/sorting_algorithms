#include "sort.h"

/**
 * swap_int - It swaps two elements in an array, 
 * @a: The first element, 
 * @b: The second element. 
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - It partition through an array of integers
 * @array: An array of integers
 * @size: The size of the array, 
 * @l: The first index of array, 
 * @h: The last index of array, 
 *
 * Description: All the values must be accurate, 
 * Return: New index position. 
 */
int lomuto_partition(int *array, size_t size, int l, int h)
{
	int pivot = array[h], i = l, j;

	for (j = l; j <= h - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (pivot != array[i])
	{
		swap_int(&array[i], &array[h]);
		print_array(array, size);
	}
	return (i);
}

/**
 * lomuto_sort - It perform and implement quick sort
 * @array: An array
 * @size: The size of the array
 * @l: The first index of the array. 
 * @h: The last index of the array. 
 * Return: 0 will return. 
 */

void lomuto_sort(int *array, size_t size, int l, int h)
{
	int i;

	if (l < h)
	{
		i = lomuto_partition(array, size, l, h);
		lomuto_sort(array, size, l, i - 1);
		lomuto_sort(array, size, i + 1, h);
	}
}

/**
 * quick_sort -It sort an array of an integer
 * @array: Anarray
 * @size: The size of the array
 * Return: 0
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
