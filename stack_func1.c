#include "monty.h"


/**
 * addToStack - Adds a node to the stack.
 * @nNode: Pointer to the new node.
 * @lnum: Interger representing the line number of of the opcode.
 */
void addToStack(stack_t **nNode, __attribute__((unused))unsigned int lnum)
{
	stack_t *temp;

	if (nNode == NULL || *nNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nNode;
		return;
	}
	temp = head;
	head = *nNode;
	head->next = temp;
	temp->prev = head;
}


/**
 * pStack - Adds a node to the stk.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @lnum: line number of  the opcode.
 */
void pStack(stack_t **stk, unsigned int lnum)
{
	stack_t *temp;

	(void) lnum;
	if (stk == NULL)
		exit(EXIT_FAILURE);
	temp = *stk;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * popTop - Adds a node to the stk.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @lnum: Interger representing the line number of of the opcode.
 */
void popTop(stack_t **stk, unsigned int lnum)
{
	stack_t *temp;

	if (stk == NULL || *stk == NULL)
	moreErrrr(7, lnum);

	temp = *stk;
	*stk = temp->next;
	if (*stk != NULL)
		(*stk)->prev = NULL;
	free(temp);
}

/**
 * priTop - Prints the top node of the stk.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @lnum: Interger representing the line number of of the opcode.
 */
void priTop(stack_t **stk, unsigned int lnum)
{
	if (stk == NULL || *stk == NULL)
	moreErrrr(6, lnum);
	printf("%d\n", (*stk)->n);
}
