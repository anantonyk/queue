#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0
typedef struct Element
{
	int value;
	struct Element * next;
} Element;
extern Element* createElement(int value_);

typedef struct SafeQueue
{
		Element *first;
		Element *last;
} SafeQueue;

SafeQueue* createQueue();
void destroyQueue();
int size();
bool empty();
Element* front(SafeQueue *q);
Element* back(SafeQueue *q);
void push(SafeQueue *q, Element *item);
Element* pop(SafeQueue *q);
void display(SafeQueue *q);
