#include "monty.h"

/**
 * opFile - opens a file
 * @fname: the file namepath
 */

void opFile(char *fname)
{
	FILE *fd = fopen(fname, "r");

	if (fname == NULL || fd == NULL)
        errrr(2, fname);

    Rfile(fd);
	fclose(fd);
}


/**
 * Rfile - reads a file
 * @fdir: pointer to file descriptor
 */

void Rfile(FILE *fdir)
{
	int liNum, fmat = 0;
	char *buffer = NULL;
	size_t liN = 0;

	for (liNum = 1; getline(&buffer, &liN, fdir) != -1; liNum++)
	{
		fmat = prsLine(buffer, liNum, fmat);
	}
	free(buffer);
}


/**
 * prsLine - Separates each line into tokens to determine
 * which function to call
 * @buf: line from the file
 * @lnum: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int prsLine(char *buf, int lnum, int format)
{
	char *oppppo_code, *vlu;
	const char *nLine = "\n ";

	if (buf == NULL)
        errrr(4);

	oppppo_code = strtok(buf, nLine);
	if (oppppo_code == NULL)
		return (format);

	vlu = strtok(NULL, nLine);
	if (strcmp(oppppo_code, "stack") == 0)
		return (0);

	if (strcmp(oppppo_code, "queue") == 0)
		return (1);

    fFunc(oppppo_code, vlu, lnum, format);
	return (format);
}

/**
 * fFunc - find the appropriate function for the oppocode
 * @oppocode: oppocode
 * @vlu: argument of oppocode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @lnum: line number
 * if 1 nodes will be entered as a queue.
 */
void fFunc(char *oppocode, char *vlu, int lnum, int format)
{
	int num;
	int kickOut;

	instruction_t func_list[] = {
		{"push",   addToStack},
		{"pall",   pStack},
		{"pint",   priTop},
		{"pop",    popTop},
		{"nop",   nop},
		{"swap",  swapNod},
		{"add",   addNod},
		{"sub",   subNod},
		{"div",   divNod},
		{"mul",   mulNod},
		{"mod",   modNod},
		{"pchar", ptc},
		{"pstr",  pts},
		{"rot",   rot},
		{"rotr",  rotr},
		{NULL, NULL}
	};

	if (oppocode[0] == '#')
		return;

	for (kickOut = 1, num = 0; func_list[num].opcode != NULL; num++)
	{
		if (strcmp(oppocode, func_list[num].opcode) == 0)
		{
            cFun(func_list[num].f, oppocode, vlu, lnum, format);
			kickOut = 0;
		}
	}
	if (kickOut == 1)
        errrr(3, lnum, oppocode);
}


/**
 * cFun - Calls the required function.
 * @funcc: Pointer to the function that is about to be called.
 * @opppo: string representing the opcode.
 * @vlu: string representing a numeric value.
 * @lnum: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void cFun(op_func funcc, char *opppo, char *vlu, int lnum, int format)
{
	stack_t *nd;
	int kickOut;
	int num;

	kickOut = 1;
	if (strcmp(opppo, "push") == 0)
	{
		if (vlu != NULL && vlu[0] == '-')
		{
            vlu = vlu + 1;
			kickOut = -1;
		}
		if (vlu == NULL)
            errrr(5, lnum);
		for (num = 0; vlu[num] != '\0'; num++)
		{
			if (isdigit(vlu[num]) == 0)
                errrr(5, lnum);
		}
		nd = creNode(atoi(vlu) * kickOut);
		if (format == 0)
			funcc(&nd, lnum);
		if (format == 1)
            addToQueue(&nd, lnum);
	}
	else
		funcc(&head, lnum);
}