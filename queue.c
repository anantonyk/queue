#include "queue.h"
#define MAX_SIZE 100

Element * createElement(int value_)
{
	Element *e = (Element *) malloc(sizeof(Element));
	if(e != NULL)
	{
		e->value = value_;
		e->next = NULL;
		return e;
	}
	return NULL;
}

SafeQueue* createQueue()
{
	SafeQueue *q = (SafeQueue *)malloc(sizeof(SafeQueue));
	if(q != NULL)
	{
		q->first = NULL;
		q->last = NULL;
		q->size=0;
		if(pthread_mutex_init(&q->mutex,NULL) != 0)
			return NULL;
		return q;
	}
	return NULL;
}

bool empty(SafeQueue *q)
{
	if(!q) 
		return true;
	pthread_mutex_lock(&q->mutex);
	bool isempty = q->size == 0 ? 1 : 0;
	pthread_mutex_unlock(&q->mutex);
	return isempty;
	
}

int size(SafeQueue *q)
{
	if(!q) 
		return -1;
	pthread_mutex_lock(&q->mutex);
	int length = q->size;
	pthread_mutex_unlock(&q->mutex);
	return length;
}

Element* front(SafeQueue *q)
{
	if(!q) 
		return NULL;
	pthread_mutex_lock(&q->mutex);
	Element * tmp = q->first;
	pthread_mutex_unlock(&q->mutex);
	return tmp;
}

Element* back(SafeQueue *q)
{
	if(!q) 
		return NULL;
	pthread_mutex_lock(&q->mutex);
	Element * tmp = q->last;
	pthread_mutex_unlock(&q->mutex);
	return tmp;
}

void destroyQueue(SafeQueue *q)
{
	if(!q) 
		return;
	pthread_mutex_lock(&q->mutex);
	Element *tmp;
	while(q->first != NULL)
	{
		tmp = q->first;
		q->first = q->first->next;
		free(tmp);
	}
	pthread_mutex_unlock(&q->mutex);
	free(q);
}

void push(SafeQueue *q, Element * element)
{
	if(!q) 
		return;
	pthread_mutex_lock(&q->mutex);
	if(q->first == NULL)
	{
		q->first = element;
		q->last = element;
		q->size++;
		pthread_mutex_unlock(&q->mutex);
		return;
	}	
	if(q->size > MAX_SIZE){
		pthread_mutex_unlock(&q->mutex);
		printf("Your queue is full\n");
		return;
	}
	q->last->next = element;
	q->last = element;
	q->size++;
	pthread_mutex_unlock(&q->mutex);
}

Element* pop(SafeQueue *q)
{
	if(!q) 
		return NULL;
	if(q->first == NULL) {
		printf("Already empty\n");
		return NULL;
	}
	pthread_mutex_lock(&q->mutex);
	struct Element * tmp = q->first;
	q-> first = q-> first-> next;
	q->size--;
	pthread_mutex_unlock(&q->mutex);
	return tmp;
}

void display(SafeQueue *q)
{
	if(!q) 
		return;
	pthread_mutex_lock(&q->mutex);
	Element *tmp = q->first;
	printf("Display queue:\n");
	while(tmp != NULL)
	{
		printf("%d ",tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
	pthread_mutex_unlock(&q->mutex);
}
