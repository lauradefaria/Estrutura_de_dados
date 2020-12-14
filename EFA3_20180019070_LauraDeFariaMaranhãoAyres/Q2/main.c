#include "Ex1.h"

int main(){
    
    Arv* broto = arv_cria(arv_criano(1, 
                            arv_criano(3, NULL, 
								arv_criano(5, NULL, NULL)),  
		                            arv_criano(4, 
		                                arv_criano(6, NULL, NULL), 
		                                    arv_criano(7, NULL, NULL))));

    arv_imprime(broto);     //formato (raiz<sae><sad>) 

    printf("\nNumero pares da arvore: %d\n", pares(broto));
    printf("Numero de folhas: %d\n", folhas(broto));
    printf("Apenas possuem um filho: %d\n", filhos(broto));

    arv_libera(broto);
}

