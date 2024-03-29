#include <stdio.h>
#include "sort.h"

/**
 * swap - It swapped two elements in an array
 * @a: It Point's to the first element
 * @b: It Point's to the second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * sift_down - It performs the sift-down operation on a heap, 
 * @array: An array that represent the heap, 
 * @size: The size of the heap, 
 * @root: The index of the root of the subtree to sift-down, 
 * @end: It is the index of the last element in the heap. 
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t max, left, right;

    	max = root;
	left = 2 * root + 1;
	right = 2 * root + 2;

    if (left < end && array[left] > array[max])
        max = left;

    if (right < end && array[right] > array[max])
        max = right;

    if (max != root)
    {
        swap(&array[root], &array[max]);
        print_array(array, size);
        sift_down(array, size, max, end);
    }
}

/**
 * heap_sort - It sorts the array of an integers in ascending order
 * using the Heap sort algorithm (sift-down approach)
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (array == NULL || size < 2)
            return;
    for (i = size / 2 - 1; i >= 0; i--)
        sift_down(array, size, i, size);

    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        sift_down(array, size, 0, i);
    }
}
