#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct pes Pessoa;
typedef struct hash Hash;
int hash_2(Hash* tabela, int cpf)
int hash(Hash* tabela, int cpf);
Hash* hash_create();
Pessoa* pes_create(char* nome, int cpf);
void hash_free(Hash** tabela);
void redimenciona (Hash** tabela);
Pessoa* hash_search(Hash* tabela, int cpf);
Pessoa* hash_insert(Hash** tabela, Pessoa* indv);
void print_hash(Hash *tabela);
