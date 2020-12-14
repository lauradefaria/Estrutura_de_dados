#include "NovoArquivo.h"

L_no * create_no(int info)                     //Cria um n� na lista
{
	L_no* nozinho = (L_no*) malloc(sizeof(L_no));   //Aloca o espa�o de mem�ria do n�
	
	if(nozinho){
		nozinho->info = info;
		nozinho->proximo = NULL;
	}
	
	return nozinho;
}

int insert_sorted(L_no** lhead, int info)      //Insere ordenadamente os elementos na lista
{   
	
	L_no* novo = create_no(info);      //Aloca��o de mem�ria
	L_no* anterior = NULL;             //ponteiro para elemento anterior 
	L_no* lista = *lhead;               //ponteiro para percorrer a lista
	
	/* Verifica se a aloca��o do n� foi bem sucedida*/
	if(!novo){
		printf("Erro de aloca��o de mem�ria/n");
		return 1;
	}
		
 	 /* Percorre a lista a procura da posi��o de inser��o */
	 while (lista != NULL && lista->info < info) {    
		anterior = lista;                           
		lista = lista->proximo;
	 } 
	 
	 /* insere elemento */
	 if (anterior == NULL) {                //insere elemento no in�cio 
	 	 novo->proximo = *lhead;
	 	 *lhead = novo;
	 }
	 else{                                 //insere elemento no meio da lista
	 	 novo->proximo = anterior->proximo;
	 	 anterior->proximo = novo;
	 }
	 
	 return 0;
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

int exists(L_no* lhead, int info)              //Procura um determinado elemento na lista
{
	L_no* lista = lhead;
	
	while(lista != NULL){
		if(lista->info == info)
			return 1;
		
		lista = lista->proximo;
	}
	
	return 0;
}

void print_Conjunto(L_no* lhead, char letra)   //Imprime todos os elementos do conjunto
{
	
	L_no* lista = lhead;
	int i;
	printf("%c = {", letra);
		
	for(i=0; i < l_size(lhead); i++){        //Percorre a lista e imprime cada termo
		printf("%d",lista->info);
		lista = lista->proximo;
		
		if(i != (l_size(lhead)-1)){          //Coloca a v�rgura para separar enquanto n�o chegar no fim
			printf(", ");
		}
	}
	printf("}\n");
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

int remove_item(L_no** lhead, int info){       //Remove elemento da lista
	L_no* anterior = NULL;                    //Ponteiro para elemento anterior
	L_no* lista = *lhead;                     //Ponteiro para percorrer a lista
	
    /* Procura elemento na lista, guardando anterior */
	while (lista != NULL && lista->info != info) {
		anterior = lista;
		lista = lista->proximo;
	}
	
    /* Verifica se achou elemento */
	if(empty(lista)){
		return 0;
	}

    /* Retira elemento */
	if (anterior == NULL) {                  //Retira o elemento do inicio 
		*lhead = lista->proximo;    
	}
	else {                                   //Retira o elemento do meio da lista    
		anterior->proximo = lista->proximo;
	}
	
	free(lista);
	return 0;
}

void uniao(L_no* lhead_A, L_no* lhead_B, L_no** lhead_R)       //Realiza a uni�o de dois conjuntos
{
	int i;
	L_no *lista_A = lhead_A;
	L_no *lista_B = lhead_B;
	
	for(i=0; i < l_size(lhead_A); i++){                   //Compara cada termo do conjunto (A) com o resultante (R)
		if(!exists(*lhead_R, lista_A->info)){             //Se o termo do conjunto n�o existir no resultante, ele insere ordenadamente
			insert_sorted(lhead_R, lista_A->info);
		}	
		lista_A = lista_A->proximo;	
	}
	
	for(i=0; i < l_size(lhead_B); i++){                   //Compara cada termo do conjunto (B) com o resultante (R)
		if(!exists(*lhead_R,lista_B->info)){              //Se o termo do conjunto n�o existir no resultante, ele insere ordenadamente
			insert_sorted(lhead_R,lista_B->info);
		}	
		lista_B = lista_B->proximo;		
	}
}

void interseccao(L_no* lhead_A, L_no* lhead_B, L_no** lhead_R) //Realiza a intersec��o de dois conjuntos
{
	int i;
	L_no *lista_A = lhead_A;
	L_no *lista_B = lhead_B;
	
	for(i=0; i < l_size(lhead_B); i++){                  //Compara cada termo do conjunto (B) com o resultante (R)
		if(exists(lista_A,lista_B->info)){               //Se o termo do conjunto existir no resultante, ele insere ordenadamente
			insert_sorted(lhead_R,lista_B->info);
		}	
		lista_B = lista_B->proximo;		
	}
}

int maior(L_no* lhead)                                         //Encontra o maior elemento na lista
{
	L_no * lista = lhead;
	int i, valor;
	
	for(i=0; i < l_size(lhead); i++){          //Percorre a lista at� o �ltimo elemento e armazena o seu valor
		valor = lista->info;
		lista = lista->proximo;
	}
	
	return valor;                              //Retorna o �ltimo elemento da lista, j� que ela est� ordenada de forma crescente
}

int iguais(L_no* lhead_A, L_no* lhead_B)                       //Checa se os conjuntos s�o iguais
{
	L_no* lista_A = lhead_A;
	L_no* lista_B = lhead_B;
	int tamanho_A = l_size(lhead_A);
	int tamanho_B = l_size(lhead_B);
	int cont = 0, i;
	
	if(tamanho_A == tamanho_B){
		
		for(i=0; i < tamanho_A; i++){                        //Compara cada termo do conjunto (A) com o outro (B)
			if(exists(lista_B, lista_A->info)){              //Se o termo do conjunto existir no resultante, ele incrementa o contador
				cont++;
			}	
			lista_A = lista_A->proximo;	
		}
		
		if(cont == tamanho_B){                                //se o contador for do tamnho do conjunto, significa que s�o iguais
			return 1;
		}
		else{
			return 0;
		}
	}		
	else{                                                     //Se n�o forem do mesmo tamanho, retorna zero(diferentes)
		return 0;
	}	
}

void diferenca(L_no* lhead_A, L_no* lhead_B, L_no** lhead_R)   //Realiza a diferen�a entre os dois conjuntos
{
	L_no* lista_A = lhead_A;
	L_no* lista_B = lhead_B;
	int  i;
		
	for(i=0; i < l_size(lhead_B); i++){                         
		insert_sorted(lhead_R,((lista_A->info) - (lista_B->info)));    //Insere no conjunto resultante a diferen�a A-B
		
		lista_B = lista_B->proximo;
		lista_A = lista_A->proximo;	
	}	
}