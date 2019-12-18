#include "queue.h"

Element * createElement(int value_)
{
	Element *e = (Element *) malloc(sizeof(Element));
	if(e!=NULL)
	{
		e->value = value_;
		e->next=NULL;
		return e;
	}
	return NULL;
}

SafeQueue* createQueue()
{
	SafeQueue *q = (SafeQueue *) malloc(sizeof(SafeQueue));
	if(q!=NULL)
	{
		q->first = NULL;
		q->last = NULL;
		return q;
	}
	return NULL;
}

bool empty(SafeQueue *q)
{
	if(!q) return true;
	return (size(q) == 0);
}

int size(SafeQueue *q)
{
	if(!q) return -1;
	Element * tmp = q->first;
	int length = 0;
	while(tmp!=NULL)
	{
		length++;
		tmp = tmp->next;
	}
	return length;
}

Element* front(SafeQueue *q)
{
	if(!q) return NULL;
	return q->first;
}

Element* back(SafeQueue *q)
{
	if(!q) return NULL;
	return q->last;
}

void destroyQueue(SafeQueue *q)
{
	if(!q) return;
	Element *tmp;
	while(q->first!=NULL)
	{
		tmp = q->first;
		q->first=q->first->next;
		free(tmp);
	}
	free(q);
}

void push(SafeQueue *q, Element * element)
{
	if(!q) return;
	if(q->first==NULL)
	{
		q->first =element;
		q->last = element;
		return;
	}	
	q->last->next = element;
	q->last = element;
}

Element* pop(SafeQueue *q)
{
	if(!q) return NULL;
	if(q->first==NULL) return NULL;
	struct Element * tmp = q->first;
	q-> first = q-> first-> next;
	return tmp;
}

void display(SafeQueue *q)
{
	printf("Display queue:\n");
	if(!q) return;
	Element *tmp = q->first;
	while(tmp!= NULL)
	{
		printf("%d ",tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}
