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

extern SafeQueue* createQueue();
extern void destroyQueue();
extern int size();
extern bool empty();
extern Element* front(SafeQueue *q);
extern Element* back(SafeQueue *q);
extern void push(SafeQueue *q, Element *item);
extern void pop(SafeQueue *q);
extern void display(SafeQueue *q);
