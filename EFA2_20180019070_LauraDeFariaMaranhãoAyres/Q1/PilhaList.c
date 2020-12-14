#include "PilhaList.h"

L_no * create_no(int info)                     //Cria um n� na lista
{
	L_no* nozinho = (L_no*) malloc(sizeof(L_no));   //Aloca o espa�o de mem�ria do n�
	
	if(nozinho){
		nozinho->info = info;                  //Armazena as informa��es e ponteiro aponta para NULL
		nozinho->proximo = NULL;
	}
	
	return nozinho;
}

int l_size(L_no* lhead)                        //Verifica o tamanho da lista
{
	int cont = 0;
	
	while(lhead != NULL){  //Percorre a lista, incrementando o contador a cada elemento passado
		cont++;
		lhead = lhead->proximo;
	}
	
	return cont;                               //Retorna o contador
}

int empty(L_no* lhead)                         //Verifica se a lista est� vazia
{
	if(lhead == NULL){
		return 1;
	}
	return 0;
}

void clear_list(L_no** lhead)                  //Esvazia a lista
{
	L_no *lista = *lhead;                   
	L_no *lista_proximo;                      //Ponteiro para o pr�ximo elemento da lista
	
	while(lista != NULL){                     //Libera os elementos da lista 
		lista_proximo = lista->proximo;
		free(lista);
		lista = lista_proximo;
	}
	*lhead = NULL;                            //Cabe�a da lista aponta para NULL, indicando que est� vazia
}

int stack_push(L_no** lhead, int info)        //Insere um elemento no fim da pilha
{
	L_no* stk = create_no(info);
	
	if(stk){
		if(empty(*lhead)){                    //Caso a lista esteja vazia, insere na primeira posi��o
		
			stk->proximo = *lhead;
			*lhead = stk;
			return 0;
			
		}
		
		L_no* lista = *lhead;
		while(lista->proximo != NULL){       //Avan�a at� a �ltima posi��o da pilha e insere
			lista = lista->proximo;
		}
		
		lista->proximo = stk;
		return 0;
	}
	
	return 1;
}

int stack_pop(L_no** lhead)
{	
	/* Verifica se a lista est� vazia */
	if(empty(*lhead)){
		return 1;
	}

	L_no* lista = *lhead;                     //Ponteiro para percorrer a lista
	
    /* Procura o �ltimo elemento na lista*/
	while (lista->proximo != NULL) {
		lista = lista->proximo;
	}

    /* Retira esse elemento (LIFO) */
	*lhead = lista;    
	free(lista);
	
	return 0;
}

void print_stack(L_no* lhead)                //Imprime todos os elementos da pilha
{
	
	L_no* lista = lhead;
	int i;
	printf("Pilha = [");
		
	for(i=0; i < l_size(lhead); i++){        //Percorre a lista e imprime cada termo
		printf("%d",lista->info);
		lista = lista->proximo;
		
		if(i != (l_size(lhead)-1)){          //Coloca a v�rgura para separar enquanto n�o chegar no fim
			printf(", ");
		}
	}
	printf("]\n");
}