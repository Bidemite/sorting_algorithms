/* 101-cocktail_sort_list.c */

#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - It swaps two nodes in a doubly linked list.
 *
 * @list: It Point's to the pointer to the head of the list.
 * @left: It Point's to the left node to be swapped.
 * @right: It point's to the right node to be swapped.
 */
static void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;

	print_list(*list);
}

/**
 * cocktail_sort_list - It sorts a doubly linked list of a integers sort algorithm.
 *
 * @list: It point's to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *tmp;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;

		/* Forward pass: Bubble sort from left to right */
		for (tmp = *list; tmp->next != NULL; tmp = tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				swap_nodes(list, tmp, tmp->next);
				swapped = 1;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		tmp = tmp->prev; /* Move tmp to the last node */

		/* Backward pass: Bubble sort from right to left */
		for (; tmp->prev != NULL; tmp = tmp->prev)
		{
			if (tmp->n < tmp->prev->n)
			{
				swap_nodes(list, tmp->prev, tmp);
				swapped = 1;
			}
		}
	} while (swapped);
}
