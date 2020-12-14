#include "Hash_DispersaoDupla.h"

struct pes{
	char nome[100];
	int cpf;         // 5 ultimos números do cpf da pessoa
};

struct hash{         //struct da tabela hash
	int tamanho;
	int elementos;
	Pessoa** vetor;
};

int hash_2(Hash* tabela, int cpf){
	return  tabela->tamanho - 2 - cpf%(tabela->tamanho - 2);
}

int hash(Hash* tabela, int cpf)
{
	return cpf%tabela->tamanho;
}

Hash* hash_create()
{                                       
	int i;
	Hash* h = (Hash*) malloc(sizeof (Hash));   //Aloca memória tabela
	h->vetor = (Pessoa**) malloc(13*sizeof(Pessoa*)); //Aloca memória vetor
	
	for(i=0; i<13 ; i++){
		h-> vetor[i] = NULL;
	}
	
	h->tamanho = 13;                 //tamanho total
	h->elementos = 0;
	
	return h;
}

Pessoa* pes_create(char* nome, int cpf)
{
	Pessoa* pes = (Pessoa*) malloc(sizeof(Pessoa));
	
	strcpy(pes->nome, nome);
	pes->cpf = cpf;
	
	return pes;
}

void hash_free(Hash** tabela)
{
	int i;
	Hash* tab = *tabela;
	
	for(i=0; i< tab->tamanho; i++){
		if(tab->vetor[i])
			free(tab->vetor[i]);
	}
	
	free(tab->vetor);
	free(*tabela);
}

void redimenciona (Hash** tabela)
{
	
	Hash* hsh = *tabela;
	int i;
	int anterior = hsh->tamanho;
	Pessoa** pes = hsh->vetor;
	
	hsh->elementos = 0;
	hsh->tamanho *= 1.947;
	hsh->vetor = (Pessoa**) malloc(hsh->tamanho*sizeof(Pessoa*));
	
	for(i=0; i< hsh->tamanho; ++i) {
		hsh->vetor[i] = NULL;
	}
	for(i=0; i<anterior; ++i){
		if(pes[i]){
			hash_insert(tabela, pes[i]);
		}
	}
	
	free(pes);
}

Pessoa* hash_search(Hash* tabela, int cpf)
{
	int h = hash(tabela, cpf);
	int h2 = hash2(tabela, cpf);
	
	while(tabela->vetor[h] != NULL){
		if(tabela->vetor[h]->cpf == cpf){
			return tabela->vetor[h];
		}
		h = (h+h2) % tabela->tamanho;
	}
	
	return NULL;
}

Pessoa* hash_insert(Hash** tabela, Pessoa* indv)
{
	int h = hash(*tabela, indv->cpf);
	int h2 = hash2(*tabela, indv->cpf);
	Hash* tab = *tabela;
	
	if(tab->elementos>(0.75*tab->tamanho)){
		redimenciona(tabela);
	}
	
	while(tab->vetor[h] != NULL){
		h = (h+h2) % tab->tamanho;
	}
	
	tab->vetor[h] = indv;
	tab-> elementos++;
	
	return indv;
}

void print_hash(Hash *tabela)
{
	int i;
	for (i = 0; i < tabela->tamanho; i++){
		
		if (tabela->vetor[i] != NULL){
			
			printf("Nome: %s, CPF: %d\n", tabela->vetor[i]->nome, tabela->vetor[i]->cpf);
		}
	}
}