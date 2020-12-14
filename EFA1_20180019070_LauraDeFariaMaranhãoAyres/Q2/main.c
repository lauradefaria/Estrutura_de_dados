#include "NovoArquivo.h"

int main(void)
{
	L_no* conjunto_A = NULL;
	L_no* conjunto_B = NULL;
	L_no* conjunto_R = NULL;
	int i;

	for(i=1; i<7; i++){
		insert_sorted(&conjunto_A, (i*2));
		insert_sorted(&conjunto_B, i);
	}

	print_Conjunto(conjunto_A, 'A');
	print_Conjunto(conjunto_B, 'B');
	
	printf("\na-) Uniao:\n");
	uniao(conjunto_A,conjunto_B, &conjunto_R);
	print_Conjunto(conjunto_R, 'R');
	
	printf("\nb-) Criar um conjunto vazio:\n");
	L_no* conjunto_C = NULL;
	print_Conjunto(conjunto_C, 'C');
	
	printf("\nc-) Insere:\n");
	insert_sorted(&conjunto_C, 4);
	print_Conjunto(conjunto_C, 'C');
	
	printf("\nd-) Remove:\n");
	remove_item(&conjunto_C, 4);
	print_Conjunto(conjunto_C, 'C');
	
	printf("\ne-) Interseccao:\n");
	clear_list(&conjunto_R);
	interseccao(conjunto_A,conjunto_B, &conjunto_R);
	print_Conjunto(conjunto_R, 'R');
	
	printf("\nf-) Diferenca:\n");
	clear_list(&conjunto_R);
	diferenca(conjunto_A,conjunto_B, &conjunto_R);
	print_Conjunto(conjunto_R, 'R');
	
	printf("\ng-) Testa se um numero pertence ao conjunto:\n");
	if(exists(conjunto_A, 2)){
		printf("O numero 2 pertence ao conjunto A\n");
	}
	else{
		printf("O numero 2 nao pertence ao conjunto A\n");
	}
	 
	printf("\nh-) Menor valor:\n");                                  //Como foi inserido de forma ordenada, o menor valor
	printf("Menor valor do conjunto B: %d\n", conjunto_B->info);	 //            será o primeiro da lista
	
	printf("\ni-) Maior valor:\n");
	printf("Menor valor do conjunto B: %d\n", maior(conjunto_B));
	
	printf("\nj-) Testa se os conjuntos sao iguais:\n");
	if(iguais(conjunto_A,conjunto_B))
	{
		printf("Os conjuntos sao iguais\n");
	}
	else{
		printf("Os conjuntos nao sao iguais\n");
	}
	
	printf("\nk-) Retorna o Tamanho do conjunto:\n");
	printf("Tamanho do conjunto A: %d\n", l_size(conjunto_A));
	
	printf("\nl-)Testa se o conjunto e vazio:\n");
	if(empty(conjunto_A)){
		printf("O conjunto A esta vazio\n");
	}
	else{
		printf("O conjunto A nao esta vazio\n");
	}
}