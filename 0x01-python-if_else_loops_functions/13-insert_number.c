#include "lists.h"

/**
 * insert_node - Inserts  number into a sorted singly-linked lists
 * @head: A pointer head of the linked lists
 * @number: Number to inserts
 *
 * Return: If function fails - NULL.
 * Otherwise - pointer to new node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = *head, *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;

	if (node == NULL || node->n >= number)
	{
		new->next = node;
		*head = new;
		return (new);
	}

	while (node && node->next && node->next->n < number)
		node = node->next;

	new->next = node->next;
	node->next = new;

	return (new);
}
