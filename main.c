#include "monty.h"
stack_t *head = NULL;
/**
 * main - entry point
 * @argccc: arguments count
 * @argvvv: list of arguments
 * Return: always 0
 */
int main(int argccc, char *argvvv[])
{
	if (argccc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opFile(argvvv[1]);
	frNodes();
	return (0);
}

/**
 * creNode - Creates a node.
 * @numberr: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *creNode(int numberr)
{
	stack_t *nod;

	nod = malloc(sizeof(stack_t));
	if (nod == NULL)
		errrr(4);
	nod->next = NULL;
	nod->prev = NULL;
	nod->n = numberr;
	return (nod);
}

/**
 * frNodes - Frees nodes in the stack.
 */
void frNodes(void)
{
	stack_t *TMP;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		TMP = head;
		head = head->next;
		free(TMP);
	}
}


/**
 * addToQueue - Adds a node to the queue.
 * @nNod:Pointer to the new node.
 * @lnum: line number of the opcode.
 */
void addToQueue(stack_t **nNod, __attribute__((unused))unsigned int lnum)
{
	stack_t *TMP;

	if (nNod == NULL || *nNod == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nNod;
		return;
	}
	TMP = head;
	while (TMP->next != NULL)
		TMP = TMP->next;

	TMP->next = *nNod;
	(*nNod)->prev = TMP;

}
