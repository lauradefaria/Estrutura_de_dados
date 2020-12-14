#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

struct no                                     //Estrutura de cada elemento da lista
{
	int info;                                 //Informação da estrutura
	struct no* proximo;                       //Ponteiro para o próximo nó da lista
};

typedef struct no L_no;

L_no * create_no(int info);
int l_size(L_no* lhead);
int empty(L_no* lhead);
void clear_list(L_no** lhead);
int stack_push(L_no** lhead, int info);
int stack_pop(L_no** lhead);
void print_stack(L_no* lhead);