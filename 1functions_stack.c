#include "monty.h"

/**
 * add_to_stack - Adds a node to the stacks.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * print_stack - Adds a node to the stacks.
 * @stacks: Pointer to a pointer pointing to top node of the stacks.
 * @l_numb: line number of  the opcode.
 */
void print_stack(stack_t **stacks, unsigned int l_numb)
{
	stack_t *tmp;

	(void)l_numb;
	if (stacks == NULL)
		exit(EXIT_FAILURE);
	tmp = *stacks;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - Adds a node to the stacks.
 * @stacks: Pointer to a pointer pointing to top node of the stacks.
 * @l_numb: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stacks, unsigned int l_numb)
{
	stack_t *tmp;

	if (stacks == NULL || *stacks == NULL)
		more_err(7, l_numb);

	tmp = *stacks;
	*stacks = tmp->next;
	if (*stacks != NULL)
		(*stacks)->prev = NULL;
	free(tmp);
}

/**
 * print_top - Prints the top node of the stacks.
 * @stacks: Pointer to a pointer pointing to top node of the stacks.
 * @l_numb: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stacks, unsigned int l_numb)
{
	if (stacks == NULL || *stacks == NULL)
		more_err(6, l_numb);
	printf("%d\n", (*stacks)->n);
}
