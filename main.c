#include "monty.h"
stack_t *head = NULL;
/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opFile(argv[1]);
	frNodes();
	return (0);
}

/**
 * creNode - Creates a node.
 * @num: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *creNode(int num)
{
    stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	errrr(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = num;
	return (node);
}

/**
 * frNodes - Frees nodes in the stack.
 */
void frNodes(void)
{
    stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * addToQueue - Adds a node to the queue.
 * @nNode: Pointer to the new node.
 * @lnum: line number of the opcode.
 */
void addToQueue(stack_t **nNode, __attribute__((unused))unsigned int lnum)
{
    stack_t *tmp;

	if (nNode == NULL || *nNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nNode;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *nNode;
	(*nNode)->prev = tmp;

}