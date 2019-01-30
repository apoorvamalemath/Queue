#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 5
#define MAX_QUEUE 3

struct queue
{
	int elements[MAX];
	int front;
	int rear;
};

void initQueue(struct queue *q);
void EnQueue(struct queue *q,const int *ele);
void DeQueue(struct queue *q);
int front(const struct queue *q);
bool isEmpty(const struct queue *q);
bool isFull(const struct queue *q);
int size(const struct queue *q);
void display(const struct queue *q);

/*
	C Program to implement multiple circular queue.
*/


//#include"queue.h"



void initQueue(struct queue *q)
{
	q->front=-1;
	q->rear=-1;
}


void EnQueue(struct queue *q,const int *ele)
{
	q->rear=(q->rear+1)%MAX;
	q->elements[q->rear]=*ele;
	if(q->front==-1)
		q->front=0;
}

void DeQueue(struct queue *q)
{
	if(q->front==q->rear)
		initQueue(q);
	else
		q->front=(q->front+1)%MAX;
}

int front(const struct queue *q)
{
	return q->elements[q->front];
}

bool isEmpty(const struct queue *q)
{
	if(q->rear==-1)
		return true;
	else
		return false;
}

bool isFull(const struct queue *q)
{
	if((q->rear+1)%MAX == q->front)
		return true;
	else
		return false;
}

int size(const struct queue *q)
{
	int s;
	if(q->front ==-1)
		s=0;

	else if(q->rear>=q->front)
		s=q->rear-q->front+1;
	else
		s=(MAX-q->front)+(q->rear+1);

	return s;
}

void display(const struct queue *q)
{
	int i;
	printf("-----------------------------\n");
	for(i=q->front;i!=q->rear;i=(i+1)%MAX);
		printf("%d\n",q->elements[i]);

	//print last element
	printf("%d\n",q->elements[i]);
	printf("-----------------------------\n");
}
int main()
{
	struct queue q[MAX_QUEUE];
	int queue_number;
	int ch;
	int ele;

	printf("Initializing the queues\n");
	for(queue_number=0;queue_number<MAX_QUEUE;queue_number++)
	{
		printf("Initializing Queue %d \n",queue_number+1);
		initQueue(&q[queue_number]);
	}

	while(1)
	{
		printf("Enter the queue number on which you want to operate : ");
		scanf("%d",&queue_number);

		if(queue_number>MAX_QUEUE || queue_number<=0)
		{
			printf("Invalid Queue Number \n");
			continue;
		}

		printf("1. EnQueue\n");
		printf("2. DeQueue\n");
		printf("3. Get front element of the queue\n");
		printf("4. Get Size of the queue\n");
		printf("5. Display\n");
		printf("6. Exit\n");
		printf("Enter the choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: //If queue is not full then enQueue
				if(!isFull(&q[queue_number-1]))
				{
					printf("Enter the element to be enqueued :");
					scanf("%d",&ele);
					EnQueue(&q[queue_number-1],&ele);
				}
				else
					printf("Error : Queue Full \n");
				break;

			case 2: //If queue is not empty then deQueue
				if(!isEmpty(&q[queue_number-1]))
					DeQueue(&q[queue_number-1]);
				else
					printf("Error : Queue Empty \n");
				break;

			case 3: //If queue is not empty then get front of queue
				if(!isEmpty(&q[queue_number-1]))
				{
					ele = front(&q[queue_number-1]);
					printf("Front end of queue = %d\n",ele);
				}
				else
					printf("Error : Queue Empty \n");
				break;

			case 4: printf("Size of queue = %d\n",size(&q[queue_number-1]));
				break;

			case 5:if(!isEmpty(&q[queue_number-1]))
					display(&q[queue_number-1]);
				else
					printf("Error : Queue %d is Empty \n",queue_number);

			case 6: exit(0);

			default: printf("Invalid Choice\n");
		}
	}
	return 0;
}
