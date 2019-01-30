#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 5

struct queue
{
	int elements[MAX];
	int front;
	int rear;
};

void initQueue(struct queue *q);
void EnQueue(struct queue *q, const int *ele);
void DeQueue(struct queue *q);
int front(const struct queue *q);
int size(const struct queue *q);
bool isEmpty(const struct queue *q);
bool isFull(const struct queue *q);
void display(const struct queue *q);



void initQueue(struct queue *q)
{
	q->front=-1;
	q->rear=-1;
}


void EnQueue(struct queue *q, const int *ele)
{
	int j=q->rear;
	int data = *ele;

	int k = q->front -1;
	if(k<0)
		k = MAX-1;

	//Insertion Sort, Add the data according to priority
	while(j!=k && j>=0 && data<q->elements[j])
	{
		q->elements[(j+1)%MAX]=q->elements[j];
		j--;

		if(j<0)
			j=MAX-1;
	}

	q->elements[(j+1)%MAX]=data;
	q->rear=(q->rear+1)%MAX;
	if(q->front==-1)
		q->front=0;
}

void DeQueue(struct queue *q)
{
	int i;
	//Queue is Empty (deleting last element) reinitialize the queue
	if(q->front==q->rear)
		initQueue(q);

	else
	{
		q->front = (q->front+1) % MAX;
	}

}

int front(const struct queue *q)
{
	return q->elements[q->front];
}

int size(const struct queue *q)
{
	int s;
	if(q->rear==-1)
		s=0;
	else if(q->front <= q->rear)
		s=(q->rear-q->front)+1;
	else
		s=(MAX-q->front)+(q->rear+1);

	return s;
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


void display(const struct queue *q)
{
	int i;
	printf("------------------------\n");
	for(i=q->front;i!=q->rear;i=(i+1)%MAX)
		printf("%d\n",q->elements[i]);


	printf("%d\n",q->elements[i]);

	printf("------------------------\n");
}


int main()
{
	struct queue q;
	initQueue(&q);
	int ch;
	int ele;
	while(1)
	{
		printf("1. EnQueue \n");
		printf("2. DeQueue \n");
		printf("3. Get Front of the Queue\n");
		printf("4. Get Size of the Queue\n");
		printf("5. Display\n");
		printf("6. Exit\n");

		printf("Enter the choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: if(!isFull(&q))
				{
				  printf("Enter the data to be EnQueued :");
				  scanf("%d",&ele);
				  EnQueue(&q,&ele);
				}
				else
					printf("Error : Queue Full\n");
				break;

			case 2: if(!isEmpty(&q))
				   DeQueue(&q);
				else
					printf("Error : Queue Empty\n");
				break;

			case 3: if(!isEmpty(&q))
					printf("Front of the queue = %d\n",front(&q));
				else
					printf("Error : Queue Empty\n");
				break;

			case 4:printf("Size of the Queue = %d\n",size(&q));
				break;

			case 5:
				if(!isEmpty(&q))
					display(&q);
				else
					printf("Error : Queue Empty \n");
				break;

			case 6:exit(0);

			default: printf("Invalid Choice\n");

		}//end switch
	}//end while

	return 0;
}//end main
