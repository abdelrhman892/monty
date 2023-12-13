#include "monty.h"

/**
 * nope - Does nothing.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @lnum: Interger representing the line number of of the opcode.
 */
void nope(stack_t **stk, unsigned int lnum)
{
	(void)stk;
	(void)lnum;
}


/**
 * swapNod - Swaps the top two elements of the stk.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @lnum: Interger representing the line number of of the opcode.
 */
void swapNod(stack_t **stk, unsigned int lnum)
{
	stack_t *temp;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        moreErrrr(8, lnum, "swap");
	temp = (*stk)->next;
	(*stk)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stk;
	temp->next = *stk;
	(*stk)->prev = temp;
	temp->prev = NULL;
	*stk = temp;
}

/**
 * addNod - Adds the top two elements of the stk.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @lnum: Interger representing the line number of of the opcode.
 */
void addNod(stack_t **stk, unsigned int lnum)
{
	int sumsum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        moreErrrr(8, lnum, "add");

	(*stk) = (*stk)->next;
	sumsum = (*stk)->n + (*stk)->prev->n;
	(*stk)->n = sumsum;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}


/**
 * subNod - Adds the top two elements of the stk.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @lnum: Interger representing the line number of of the opcode.
 */
void subNod(stack_t **stk, unsigned int lnum)
{
	int sumsum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)

        moreErrrr(8, lnum, "sub");


	(*stk) = (*stk)->next;
	sumsum = (*stk)->n - (*stk)->prev->n;
	(*stk)->n = sumsum;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}


/**
 * divNod - Adds the top two elements of the stk.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @lnum: Interger representing the line number of of the opcode.
 */
void divNod(stack_t **stk, unsigned int lnum)
{
	int sumsum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        moreErrrr(8, lnum, "div");

	if ((*stk)->n == 0)
        moreErrrr(9, lnum);
	(*stk) = (*stk)->next;
	sumsum = (*stk)->n / (*stk)->prev->n;
	(*stk)->n = sumsum;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}