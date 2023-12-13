#include "monty.h"

/**
 * open_file - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
        errrr(2, file_name);

	read_file(fd);
	fclose(fd);
}


/**
 * read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_file(FILE *fd)
{
	int liNum, fmat = 0;
	char *buffer = NULL;
	size_t liN = 0;

	for (liNum = 1; getline(&buffer, &liN, fd) != -1; liNum++)
	{
		fmat = parse_line(buffer, liNum, fmat);
	}
	free(buffer);
}


/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *oppppo_code, *vlu;
	const char *nLine = "\n ";

	if (buffer == NULL)
        errrr(4);

	oppppo_code = strtok(buffer, nLine);
	if (oppppo_code == NULL)
		return (format);

	vlu = strtok(NULL, nLine);
	if (strcmp(oppppo_code, "stack") == 0)
		return (0);

	if (strcmp(oppppo_code, "queue") == 0)
		return (1);

	find_func(oppppo_code, vlu, line_number, format);
	return (format);
}

/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int num;
	int kickOut;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (kickOut = 1, num = 0; func_list[num].opcode != NULL; num++)
	{
		if (strcmp(opcode, func_list[num].opcode) == 0)
		{
			call_fun(func_list[num].f, opcode, value, ln, format);
			kickOut = 0;
		}
	}
	if (kickOut == 1)
        errrr(3, ln, opcode);
}


/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *nd;
	int kickOut;
	int num;

	kickOut = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			kickOut = -1;
		}
		if (val == NULL)
            errrr(5, ln);
		for (num = 0; val[num] != '\0'; num++)
		{
			if (isdigit(val[num]) == 0)
                errrr(5, ln);
		}
		nd = create_node(atoi(val) * kickOut);
		if (format == 0)
			func(&nd, ln);
		if (format == 1)
			add_to_queue(&nd, ln);
	}
	else
		func(&head, ln);
}
