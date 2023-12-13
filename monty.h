#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void opFile(char *fname);
int prsLine(char *buf, int lnum, int format);
void Rfile(FILE *fdir);
int len_chars(FILE *);
void fFunc(char *, char *, int, int);

/*Stack operations*/
stack_t *creNode(int num);
void frNodes(void);
void pStack(stack_t **stk, unsigned int lnum);
void addToStack(stack_t **nNode, unsigned int lnum);
void addToQueue(stack_t **nNode, unsigned int lnum);

/*Stack operations*/
void cFun(op_func funcc, char *opppo, char *vlu, int lnum, int format);

/*Stack operations*/
void priTop(stack_t **stk, unsigned int lnum);
void popTop(stack_t **stk, unsigned int lnum);
void nop(stack_t **stk, unsigned int lnum);
void swapNod(stack_t **stk, unsigned int lnum);

/*Math operations with nodes*/
void addNod(stack_t **stk, unsigned int lnum);
void subNod(stack_t **stk, unsigned int lnum);
void divNod(stack_t **stk, unsigned int lnum);
void mulNod(stack_t **stk, unsigned int lnum);
void modNod(stack_t **stk, unsigned int lnum);

/*String operations*/
void ptc(stack_t **stk, unsigned int lnum);
void pts(stack_t **stk, unsigned int lnum);
void rotl(stack_t **stk, unsigned int lnum);

/*Error handling*/
void errrr(int errCode, ...);
void moreErrrr(int errCode, ...);
void strErrrr(int errCode, ...);
void rotr(stack_t **stk, unsigned int lnum);

#endif
