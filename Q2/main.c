/*
INSTRUCTIONS:
This file must include only the main function
The main function should print out the various cases
and finally print out tables showing the performance
of various policies with the different workloads.
Vary the cache size.

You may include a function or 2 to ease the printing of tables.

*/
#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"
#include "policy.c"
#include "workload.c"
#include "queue.c"

void printQueue(queue* q){
	qnode* x = q->front;
	while (x){
		printf("%d ", x->data);
		x = x->next;
	} printf("\n");
}

int main(int argc, char* argv[])
{
	workload* w = generate_workload(RANDOM, 20, 1000);

	for(int i = 1; i<=10; i++){
		printf("Random workload on FIFO policy: %f\n", policy_FIFO(w, i));
	}
	printf("---------\n");

	for(int i = 1; i<=10; i++){
		printf("Random workload on random policy: %f\n", policy_RANDOM(w, i));
	}
	printf("---------\n");
	

	for(int i = 1; i<=10; i++){
		printf("Random workload on LRU policy: %f\n", policy_LRU(w, i));
	}
	


/*
	workload* w;
	w = generate_workload(RANDOM, 10, 100);
	int cache_size = 5;
	printf("policy_FIFO: %f\n", policy_FIFO(w, cache_size));


	printf("Loop workload\n");
	w = generate_workload(LOOP, 10, 100);
	for(int i = 0; i<w->size; i++){
		printf("%d ", w->work[i]);
	} printf("\n");


	printf("Random workload\n");
	w = generate_workload(RANDOM, 10, 100);
	for(int i = 0; i<w->size; i++){
		printf("%d ", w->work[i]);
	} printf("\n");


	printf("Local workload\n");
	w = generate_workload(LOCAL, 10, 100);
	int fr[w->pages];
	for(int i = 0; i<w->pages; i++) fr[i] = 0;
	for(int i = 0; i<w->size; i++) fr[w->work[i]]++;
	for(int i = 0; i<w->pages; i++){
		printf("%d: %d\n", i, fr[i]);
	}
*/
	
	return 0;
}