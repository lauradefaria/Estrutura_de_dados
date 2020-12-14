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
int insert_sorted(L_no** lhead, int info);
int l_size(L_no* lhead);
int exists(L_no* lhead, int info);
void print_Conjunto(L_no* lhead, char letra);
int empty(L_no* lhead);
void clear_list(L_no** lhead);
int remove_item(L_no** lhead, int info);
void uniao(L_no* lhead_A, L_no* lhead_B, L_no** lhead_R);
void interseccao(L_no* lhead_A, L_no* lhead_B, L_no** lhead_R);
int maior(L_no* lhead);
int iguais(L_no* lhead_A, L_no* lhead_B);
void diferenca(L_no* lhead_A, L_no* lhead_B, L_no** lhead_R);
