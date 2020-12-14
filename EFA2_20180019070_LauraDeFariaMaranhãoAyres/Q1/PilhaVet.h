#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

struct st{
	int* elementos;
	int tamanho;
	int total;
};

typedef struct st Stack;

Stack* create_stack();
int stack_size(Stack* stk);
bool stack_empty(Stack* stk);
int stack_push(Stack** stk, int info);
int stack_pop(Stack** stk, int *info);
void clear_stack(Stack** stk);
void print_stack(Stack* stk);
