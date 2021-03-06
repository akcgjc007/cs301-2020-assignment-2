/* 
INSTRUCTIONS:

All enum, structs and functions to be declared here.
If a definition is already declared, do not change it.
You may add extra definitions as required.

*/

#ifndef __DEF_H__
#define __DEF_H__

#include <stdio.h>
//----------------------------------------------------------------
//----------------------------------------------------------------
/* ALL ENUMERATORS HERE */

// LOOP - Workload type for Loop
// RANDOM - Workload type for RANDOM
// LOCAL - 80-20 workload type

typedef enum enum_workloads
{
	LOOP,
	RANDOM,
	LOCAL
} WorkloadsT;

//----------------------------------------------------------------
//----------------------------------------------------------------
/* ALL STRUCTS HERE */
/*
	struct for storing workload parameters and data
*/
typedef struct workload
{
	// Defines type of workload
	WorkloadsT type;
	// The number of pages in workload
	int pages;
	// The total size of the workload
	int size;
	// The final work to run the policy
	int *work;
} workload;

/*
	struct for a node in the queue
*/
typedef struct qnode
{
	int data;
	struct qnode *next;
	struct qnode *prev;
} qnode;

/*
	struct for a queue
*/
typedef struct queue
{
	qnode *front;
	qnode *back;
	int curr_size;
} queue;

/*
	File pointers for printing output
*/
FILE *time_p, *perf_p;

//----------------------------------------------------------------
//----------------------------------------------------------------
/* ALL FUNCTION DEFINITIONS HERE */

/*
	creates memory for workload parameters and work
*/
workload *generate_workload(WorkloadsT type, int pages, int size);

/*
	generates a random workload
*/
workload *generate_random(workload *w);

/*
	generates 0 - w->pages-1 looping over the w->size
*/
workload *generate_loop(workload *w);

/*
	generates the 80-20 workload(local)
*/
workload *generate_local(workload *w);

/*
	implements the FIFO policy using queue
*/
float policy_FIFO(workload *w, int cache_size);

/*
	implements the LRU policy using queue
*/
float policy_LRU(workload *w, int cache_size);

/*
	implements the RANDOM policy using queue
*/
float policy_RANDOM(workload *w, int cache_size);

/*
	implements the approx LRU using bitref and array
*/
float policy_LRUapprox(workload *w, int cache_size);

/*
	for testing a workload on all policies
*/
void test_all(workload *w, int cache_size);

/*
	create a new qnode and set the value to val
*/
qnode *new_node(int val);

/*
	create a empty queue
*/
queue *new_queue();

/*
	add into the back of the queue
*/
void push(queue *q, int data);

/*
	finds the val in the queue
		> if found, return 1
		> if not found, return 0
*/
int find(queue *q, int val);

/*
	finds the val in the queue
		> if found remove it and return 1
		> if not found return 0
*/
int find_and_remove(queue *q, int val);

/*
	removes the front element of the queue
*/
int pop(queue *q);

/*
	removes a random element from the queue
*/
void remove_random(queue *q);

/*
	copies the source queue and return the copied queue
*/
queue *copy_queue(queue *source);

/*
	printing the queue
*/
void print_queue(queue *q);


#endif /* __DEF_H__ */