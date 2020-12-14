#include "FilaVet.h"

Queue* create_queue()
{
	Queue* fila = (Queue*) malloc(sizeof(Queue));      //Aloca espaço para a fila
	
	if(!fila){
		exit(1);
	}
	
	fila->elementos = (int*) malloc(2*sizeof(int));    //Aloca memória para o vetor de elementos
	
	if(!fila->elementos){
		exit(1);
	}
	
	fila->tamanho = 0;               //Tamanho da fila
	fila->final = 0;                 //Utilizado para localizar o final da fila
	fila->inicio = 0;                //Utilizado para determinar o início da fila
	fila->total = 2;                 //Espaço de armazenamento total
	
	return fila;
}

int queue_size(Queue* q)                    //Determina o tamanho da fila
{
	return q->tamanho;
}

bool queue_empty(Queue* q)                 //Confere se a fila está vazia
{
	if(!q){
		return true;
	}
	return false;
}

int queue_insert(Queue** q, int info)       //Insere elemento no fim da fila 
{
	if(*q == NULL){               //Caso não possua fila ele cria
		*q = create_queue();
	}
	
	Queue* fila = *q;            //Ponteiro para fila
	
	/*Caso tenha atingido seu tamanho máximo*/
	if(fila->final == fila->total){  //Compara o tamanho da fila com seu espaço de armazenamento
		fila->elementos = (int*) realloc(fila->elementos, (2* fila->total) *sizeof(int)); 
		
		if(!fila->elementos){   //Erro ao alocar 
			return 1;
		}
		
		fila->total = fila->total*2;      //Dobra tamanho total
	}
	
	fila->elementos[fila->final] = info;  //insere as informações do elemento no final
	fila->final++;                        //Informa que a fila aumentou de tamanho (+1)
	fila->tamanho++;                      //Fila aumentou de tamanho 
	return 0;
}

int queue_remove(Queue** q, int *info)      //Retira elemento do início da fila
{
	if(*q == NULL){   
		return 1;
	}
	
	Queue* fila = *q;
	
	if(fila->tamanho == 0){                 //Fila vazia
		return 0;
	}
	
	*info = fila->elementos[fila->inicio];
	fila->inicio++;           //Aponta para segundo elemento do vetor
	fila->tamanho--;          //Diminui o tamanho da fila
	
	if(fila->tamanho == 0){   //quando a fila está com seu tamanho zerado
		clear_queue(q);      //libera o espaço de memória dos elementos retirados
	}
	
	return 0;
}

void clear_queue(Queue** q)    //Esvazia totalmente a fila
{
	   if(*q == NULL){         //Caso já esteja vazia, apenas retorna
		  return; 
	   }
	   
	   free((*q)->elementos);  //Libera o espaço de memória anteriormente armazenado
	   free(*q);
	   *q = NULL;	           //Vetor vazio
}

void print_queue(Queue* q)    //Imprime todos os elementos da fila
{
	
	int i;
	printf("Fila = [");
		
	for(i=0; i < queue_size(q); i++){        //Percorre a lista e imprime cada termo
		if(q->elementos[i]){
			printf("%d",q->elementos[i]);
			
			if(i != (queue_size(q)-1)){          //Coloca a vírgura para separar enquanto não chegar no fim
				printf(", ");
			}
		}
	}
	printf("]\n");
}