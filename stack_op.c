#include "monty.h"

/**
 * mulNod - Adds the top two elements of the stk.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @lnum: Interger representing the line number of of the opcode.
 */
void mulNod(stack_t **stk, unsigned int lnum)
{
	int sumsum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        moreErrrr(8, lnum, "mul");

	(*stk) = (*stk)->next;
	sumsum = (*stk)->n * (*stk)->prev->n;
	(*stk)->n = sumsum;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}


/**
 * modNod - Adds the top two elements of the stk.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @lnum: Interger representing the line number of of the opcode.
 */
void modNod(stack_t **stk, unsigned int lnum)
{
	int sumsum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)

        moreErrrr(8, lnum, "mod");


	if ((*stk)->n == 0)
        moreErrrr(9, lnum);
	(*stk) = (*stk)->next;
	sumsum = (*stk)->n % (*stk)->prev->n;
	(*stk)->n = sumsum;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
