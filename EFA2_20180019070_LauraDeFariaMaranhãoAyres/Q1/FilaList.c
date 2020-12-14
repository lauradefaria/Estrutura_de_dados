#include "FilaList.h"

L_no * create_no(int info)                      //Cria um nó na lista
{
	L_no* nozinho = (L_no*) malloc(sizeof(L_no));   //Aloca o espaço de memória do nó
	
	if(nozinho){                                    //Armazena infomações e aponta para NULL
		nozinho->info = info;
		nozinho->proximo = NULL;
	}
	
	return nozinho;
}

int l_size(L_no* lhead)                        //Verifica o tamnho da lista
{
	int cont = 0;
	
	while(lhead != NULL){  //Percorre a lista, incrementando o contador a cada elemento passado
		cont++;
		lhead = lhead->proximo;
	}
	
	return cont;
}

int empty(L_no* lhead)                         //Verifica se a lista está vazia
{
	if(lhead == NULL){
		return 1;
	}
	return 0;
}

void clear_list(L_no** lhead)                  //Esvazia a lista
{
	L_no *lista = *lhead;                   
	L_no *lista_proximo;                      //Ponteiro para o próximo elemento da lista
	
	while(lista != NULL){                     //Libera os elementos da lista 
		lista_proximo = lista->proximo;
		free(lista);
		lista = lista_proximo;
	}
	*lhead = NULL;                            //Cabeça da lista aponta para NULL, indicando que está vazia
}

int queue_insert(L_no** lhead, int info)       //Insere um elemento no fim da fila
{
	L_no* qu = create_no(info);
	
	if(qu){
	
		if(empty(*lhead)){                         //Caso a lista esteja vazia, insere na primeira posição
			
			qu->proximo = *lhead;
			*lhead = qu;
			return 0;
			
		}
		                                  	
		L_no* lista = *lhead;
		while(lista->proximo != NULL){            //Avança até a última posição da fila e insere
			lista = lista->proximo;
		}
		
		lista->proximo = qu;
		return 0;
		
	}
	
	return 1;
}

int queue_remove(L_no** lhead)                 //Remove elemento do início da fila
{
	/* Verifica se a lista está vazia */
	if(empty(*lhead)){
		return 1;
	}
	
	L_no* lista = *lhead;                     //Ponteiro para percorrer a lista

    /* Retira o primeiro elemento da fila (FIFO) */	
	*lhead = lista->proximo;    	
	free(lista);
	
	return 0;
}

void print_queue(L_no* lhead)                //Imprime todos os elementos da fila
{
	
	L_no* lista = lhead;
	int i;
	printf("Fila = [");
		
	for(i=0; i < l_size(lhead); i++){        //Percorre a lista e imprime cada termo
		printf("%d",lista->info);
		lista = lista->proximo;
		
		if(i != (l_size(lhead)-1)){          //Coloca a vírgura para separar enquanto não chegar no fim
			printf(", ");
		}
	}
	printf("]\n");
}