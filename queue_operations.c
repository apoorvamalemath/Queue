#include<stdio.h>

struct queue
{
    int item[20];
    int front;
    int rear;
};

typedef struct queue queue;

int isempty(queue q)
{
    if(q.front==-1)
        return 1;
    else
        return 0;
}

int isfull(queue q)
{
    if(q.rear==19)
        return 1;
    else
        return 0;
}

void enqueue(queue *pq,int num)
{
    if(isfull(*pq))
    {
        printf("Queue is full\n");
        return;
    }
    pq->item[++pq->rear]=num;
    if(pq->rear==0)
        pq->front=0;
}

void dequeue(queue *pq)
{
    int num;
    if(isempty(*pq))
    {
        printf("The queue is empty\n");
        return;
    }
    num=pq->item[pq->front];
    printf("%d is dequeued\n",num);
    if(pq->front==pq->rear)
        pq->front=pq->rear=-1;
    else
        pq->front++;
}

void enqueueF(queue *q)
{
    int num;
    if(isfull(*q))
    {
        printf("Queue is full\n");
        return;
    }
    printf("Enter the number:\n");
    scanf("%d",&num);
    q->item[--q->front]=num;
}

void dequeueR(queue *q)
{
    int num;
    if(isempty(*q))
    {
        printf("Queue is empty\n");
        return;
    }
    num=q->item[q->rear--];
    printf("%d is dequeued\n",num);
}


void display(queue q)
{
    int i;
    if(isempty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    for(i=q.front;i<=q.rear;i++)
    {
        printf("%d\t",q.item[i]);
    }
    printf("\n");
}

main()
{
    queue q;
    q.front=-1;
    q.rear=-1;
    int ch,done=1,num;
    while(done)
    {
      printf("1.Enqueue Rear \n2.Dequeue front \n3.Display\n4.Enqueue front \n5.Dequeue rear\n");
      printf("Enter your choice:\n");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1: printf("Enter the number:\n");
                  scanf("%d",&num);
                  enqueue(&q,num);
                  break;
          case 2:dequeue(&q);
                 break;
          case 3:display(q);
                break;
          case 4:enqueueF(&q);
                 break;
          case 5:dequeueR(&q);
                  break;
          default: done=0;
      }
    }
}
