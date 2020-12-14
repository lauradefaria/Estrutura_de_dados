#include "Ex1.h"

struct arvno
{
    int info;
    ArvNo* esq;
    ArvNo* dir;
};

struct arv
{
    ArvNo* raiz;
};

ArvNo* arv_criano (int i, ArvNo* esq , ArvNo* dir)
{
    ArvNo* p = (ArvNo*) malloc(sizeof (ArvNo ));

    p-> info = i;
    p-> esq = esq;
    p-> dir = dir;
    return p;
}

Arv* arv_cria (ArvNo* r)
{
    Arv* a = (Arv*) malloc(sizeof (Arv));
    a-> raiz = r;
    return a;
}

void imprime (ArvNo* r)
{
    if (r != NULL ){
    printf("%d ", r-> info); 
        imprime(r-> esq); 
        imprime(r-> dir); 

    }
}

void arv_imprime (Arv* a)
{
    imprime(a-> raiz); 
}

void libera (ArvNo* r)
{
    if (r != NULL) {
        libera(r-> esq); 
        libera(r-> dir); 
        free(r); 
    }
}

void arv_libera (Arv* a)
{
    libera(a-> raiz); 
    free(a); 
}

int pares(Arv* a)
{
	return busca_par(a->raiz);     //Procura os numeros pares começando pela raiz
}

int busca_par(ArvNo* a)
{
	static int cont=0;          //Contador de números pares
    if(a == NULL){
        return 0;
    }

    busca_par(a->esq);          //Busca por profundidade (inicia pela esquerda)
    busca_par(a->dir);
    if(a->info%2 == 0){         //Caso o nó seja par, contabiliza
        cont++;
    }
    
    return cont;                //Retorna a quantidade
}

int folhas(Arv* a)
{
	return busca_folhas(a->raiz);     //Procura as folhas da árvore começando pela raiz
}

int busca_folhas(ArvNo* a)
{
	static int cont=0;          //Contador de folhas
    if(a == NULL){
        return 0;
    }

    busca_folhas(a->esq);          //Busca por profundidade (inicia pela esquerda)
    busca_folhas(a->dir);
    if(a->esq == NULL && a->dir == NULL){   //Caso o nó não possua ramificação, contabiliza
        cont++;
    }
    
    return cont;                //Retorna a quantidade
}

int filhos(Arv* a)
{
	return busca_filhos(a->raiz);     //Procura os nós da árvore começando pela raiz
}

int busca_filhos(ArvNo* a)
{
	static int cont=0;          //Contador de nós com 1 filho
    if(a == NULL){
        return 0;
    }

    busca_filhos(a->esq);          //Busca por profundidade (inicia pela esquerda)
    busca_filhos(a->dir);
    
    /*Caso o nó possua apenas uma ramificação, contabiliza*/
    if(a->esq == NULL){   
        if(a->dir != NULL){
			cont++;
		}
    }
    if(a->dir == NULL){  
        if(a->esq != NULL){
			cont++;
		}
    }
    
    return cont;                //Retorna a quantidade
}