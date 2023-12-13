#include "monty.h"

/**
 * errrr - Prints appropiate error messages determined by their error code.
 * @errCode: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void errrr(int errCode, ...)
{
	va_list agugu;
	char *oppppo;
	int lNum;

	va_start(agugu, errCode);
	switch (errCode)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(agugu, char *));
			break;
		case 3:
			lNum = va_arg(agugu, int);
			oppppo = va_arg(agugu, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", lNum, oppppo);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(agugu, int));
			break;
		default:
			break;
	}
    frNodes();
	exit(EXIT_FAILURE);
}

/**
 * moreErrrr - handles errors.
 * @errCode: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void moreErrrr(int errCode, ...)
{
	va_list agugu;
	char *oppppo;
	int lNum;

	va_start(agugu, errCode);
	switch (errCode)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(agugu, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(agugu, int));
			break;
		case 8:
			lNum = va_arg(agugu, unsigned int);
			oppppo = va_arg(agugu, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", lNum, oppppo);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(agugu, unsigned int));
			break;
		default:
			break;
	}
    frNodes();
	exit(EXIT_FAILURE);
}

/**
 * strErrrr - handles errors.
 * @errCode: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void strErrrr(int errCode, ...)
{
	va_list agugu;
	int lNum;

	va_start(agugu, errCode);
	lNum = va_arg(agugu, int);
	switch (errCode)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", lNum);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", lNum);
			break;
		default:
			break;
	}
    frNodes();
	exit(EXIT_FAILURE);
}
