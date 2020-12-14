#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

struct qu{
	int* elementos;
	int tamanho;
	int inicio;
	int final;
	int total;
};

typedef struct qu Queue;

Queue* create_queue();
int queue_size(Queue* q);
bool queue_empty(Queue* q);
int queue_insert(Queue** q, int info);
int queue_remove(Queue** q, int *info);
void clear_queue(Queue** q);
void print_queue(Queue* q);