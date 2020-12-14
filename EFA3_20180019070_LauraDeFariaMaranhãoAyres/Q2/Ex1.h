#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct arv Arv;
typedef struct arvno ArvNo;
ArvNo* arv_criano (int i, ArvNo* esq , ArvNo* dir);
Arv* arv_cria (ArvNo* r);
void imprime (ArvNo* r);
void arv_imprime (Arv* a);
void libera (ArvNo* r);
void arv_libera (Arv* a);
int pares(Arv* a);
int busca_par(ArvNo* a);
int folhas(Arv* a);
int busca_folhas(ArvNo* a);
int filhos(Arv* a);
int busca_filhos(ArvNo* a);