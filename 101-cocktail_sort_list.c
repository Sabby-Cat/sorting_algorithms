#include "sort.h"
void swap_forward(listint_t **list, listint_t **tail, listint_t **mixer);
void swap_backward(listint_t **list, listint_t **tail, listint_t **mixer);
void cocktail_sort_list(listint_t **list);
/**
 * swap_forward - Swap node in doubly-linked list of ints with forward node
 * @list: pointer to head of doubly-linked list
 * @tail: pointer to tail of doubly-linked list
 * @mixer: pointer to current swapping node of cocktail mixer
 */
void swap_forward(listint_t **list, listint_t **tail, listint_t **mixer)
{
	listint_t *tmp = (*mixer)->next;

	if ((*mixer)->prev != NULL)
		(*mixer)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*mixer)->prev;
	(*mixer)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *mixer;
	else
		*tail = *mixer;
	(*mixer)->prev = tmp;
	tmp->next = *mixer;
	*mixer = tmp;
}

/**
 * swap_backward - Swap node in doubly-linked list of ints with back node
 * @list: pointer to head of doubly-linked list
 * @tail: pointer to tail of doubly-linked list
 * @mixer: pointer to current swapping node of cocktail mixer
 */
void swap_backward(listint_t **list, listint_t **tail, listint_t **mixer)
{
	listint_t *tmp = (*mixer)->prev;

	if ((*mixer)->next != NULL)
		(*mixer)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*mixer)->next;
	(*mixer)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *mixer;
	else
		*list = *mixer;
	(*mixer)->next = tmp;
	tmp->prev = *mixer;
	*mixer = tmp;
}

/**
 * cocktail_sort_list - Sort(ascending) doubly-linked list of ints using cocktail mixer 
 * @list: pointer to head of doubly-linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *mixer;
	bool check = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (tail = *list; tail->next != NULL;)
		tail = tail->next;
	while (check == false)
	{
		check = true;
		for (mixer = *list; mixer != tail; mixer = mixer->next)
		{
			if (mixer->n > mixer->next->n)
			{
				swap_forward(list, &tail, &mixer);
				print_list((const listint_t *)*list);
				check = false;
			}
		}
		for (mixer = mixer->prev; mixer != *list;
				mixer = mixer->prev)
		{
			if (mixer->n < mixer->prev->n)
			{
				swap_backward(list, &tail, &mixer);
				print_list((const listint_t *)*list);
				check = false;
			}
		}
	}
}
