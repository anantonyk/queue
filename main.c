#include "queue.h"

void * thread_func_1(void * q)
{
	printf("thread w/1 start\n");
	Element* element[20];
	Element * e = createElement(1000);
	push((SafeQueue*)q,e);
	for(int i = 0; i < 20; i++)
	{
		element[i] = createElement(i);
		push((SafeQueue*)q,element[i]);
	}	
	printf("thread w/1 finish\n");
}
void * thread_func_2(void * q)
{
	printf("thread w/2 start\n");
		display((SafeQueue*)q);
	printf("thread w/2 finish\n");
}
void* thread_func_3(void *q)
{
	printf("thread w/3 start\n");
	for(int i=0;i<10;i++)
	{
		pop((SafeQueue*)q);
	//	printf("front: %d\n", back((SafeQueue*)q)->value);
	}
	printf("thread w/3 finish\n");
}

int main()
{
	SafeQueue *queue =(SafeQueue *)createQueue();
	printf("%s\n", empty(queue)?"true":"false");
	printf("%d\n", size(queue));
	int a = 4;
	int b = 5;
	int c = 6;
	Element * o = createElement(a);
	push(queue, o);
	Element * p = createElement(b);
	printf("%s\n", empty(queue)?"true":"false");
	printf("%d\n", size(queue));
	push(queue, p);
	printf("%s\n", empty(queue)?"true":"false");
	printf("%d\n", size(queue));
	display(queue);
	printf("back: %d\n",back(queue)->value);
	printf("front: %d\n", front(queue)->value);
	Element* t = pop(queue);
	printf("deleted item: %d\n",t->value);
	display(queue);
	pthread_t threads[20];
	for(int i=0; i< 20; i++)
	{
		if(i%3==0){
			pthread_create(&threads[i],NULL,thread_func_1,(void*)queue);
		}
		else if(i%3==1){
			pthread_create(&threads[i],NULL,thread_func_2,(void*)queue);
		}
		else{
			pthread_create(&threads[i],NULL,thread_func_3,(void*)queue);
		}
	}
	for(int i=0; i< 10; i++) {
		pthread_join(threads[i],NULL);
	}	
      return 0;
}
