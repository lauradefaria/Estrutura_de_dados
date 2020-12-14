#include "PilhaVet.h"

Stack* create_stack()                //Cria a pilha
{
	Stack* pilha = (Stack*) malloc(sizeof(Stack));    //Aloca espaço para a pilha
	
	if(!pilha){
		exit(1);
	}
	
	pilha->elementos = (int*) malloc(2*sizeof(int));  //Aloca memória para o vetor de elementos
	
	if(!pilha->elementos){
		exit(1);
	}
	
	pilha->tamanho = 0;         //Tamanho da pilha
	pilha->total = 2;           //Espaço de armazenamento total
	
	return pilha;
}

int stack_size(Stack* stk)       //Determina o tamanho da pilha
{
	return stk->tamanho;
}

bool stack_empty(Stack* stk)     //Confere se a pilha está vazia
{ 
	if(!stk){
		return true;
	}
	return false;
}

int stack_push(Stack** stk, int info)     //Insere elemento no fim da pilha
{
	if(*stk == NULL){               //Caso não possua pilha ele cria
		*stk = create_stack();
	}
	
	Stack* pilha = *stk;            //Ponteiro para pilha
	
	/*Caso tenha atingido seu tamanho máximo*/
	if(pilha->tamanho == pilha->total){  //Compara o tamanho da pilha com seu espaço de armazenamento
		pilha->elementos = (int*) realloc(pilha->elementos, (2* pilha->total) *sizeof(int));
		
		if(!pilha->elementos){    //Erro ao alocar 
			return 1;
		}
		
		pilha->total = pilha->total*2;   //Dobra tamanho total
	}
	
	pilha->elementos[pilha->tamanho] = info;    //insere as informações do elemento no final
	pilha->tamanho++;                           //Pilha aumentou de tamanho 
	return 0;
}

int stack_pop(Stack** stk, int *info)
{
	if(*stk == NULL){
		return 1;
	}
	
	Stack* pilha = *stk;
	
	if(pilha->tamanho == 0){
		return 0;
	}
	
	*info = pilha->elementos[pilha->tamanho-1];
	pilha->tamanho--;
	
	if(pilha->tamanho == 0){   //quando a pilha está com seu tamanho zerado
		clear_stack(stk);      //apaga os elementos que estavam nela
	}
	
	return 0;
}

void clear_stack(Stack** stk)    //Esvazia totalmente a pilha
{
	   if(*stk == NULL){         //Caso já esteja vazia, apenas retorna
		  return; 
	   }
	   
	   free((*stk)->elementos);  //Libera o espaço de memória anteriormente armazenado
	   free(*stk);     
	   *stk = NULL;	             //Vetor vazio
}

void print_stack(Stack* stk)    //Imprime todos os elementos da pilha
{
	
	int i;
	printf("Pilha = [");
		
	for(i=0; i < stack_size(stk); i++){        //Percorre a lista e imprime cada termo
		if(stk->elementos[i]){
			printf("%d",stk->elementos[i]);
			
			if(i != (stack_size(stk)-1)){          //Coloca a vírgura para separar enquanto não chegar no fim
				printf(", ");
			}
		}
	}
	printf("]\n");
}