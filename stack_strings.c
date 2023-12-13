#include "monty.h"

/**
 * ptc - Prints the Ascii value.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @lnum: Interger representing the line number of of the opcode.
 */
void ptc(stack_t **stk, unsigned int lnum)
{
	int asc;

	if (stk == NULL || *stk == NULL)
        strErrrr(11, lnum);

	asc = (*stk)->n;
	if (asc < 0 || asc > 127)
        strErrrr(10, lnum);
	printf("%c\n", asc);
}

/**
 * pts - Prints a string.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @lnum: Interger representing the line number of of the opcode.
 */
void pts(stack_t **stk, __attribute__((unused))unsigned int lnum)
{
	int asc;
	stack_t *temp;

	if (stk == NULL || *stk == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stk;
	while (temp != NULL)
	{
		asc = temp->n;
		if (asc <= 0 || asc > 127)
			break;
		printf("%c", asc);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rottal - Rotates the first node of the stk to the bottom.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @lnum: Interger representing the line number of of the opcode.
 */
void rottal(stack_t **stk, __attribute__((unused))unsigned int lnum)
{
	stack_t *temp;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return;

	temp = *stk;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stk;
	(*stk)->prev = temp;
	*stk = (*stk)->next;
	(*stk)->prev->next = NULL;
	(*stk)->prev = NULL;
}


/**
 * rortro - Rotates the last node of the stk to the top.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @lnum: Interger representing the line number of of the opcode.
 */
void rortro(stack_t **stk, __attribute__((unused))unsigned int lnum)
{
	stack_t *temp;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return;

	temp = *stk;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stk;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stk)->prev = temp;
	(*stk) = temp;
}