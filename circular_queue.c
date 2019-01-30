
#include<stdio.h>

struct queue
{
    int item[5];
    int front;
    int rear;
};

typedef struct queue queue;
int count=0;

void enqueue(queue *pq,int num)
{
    if(count>=5)
    {
        printf("Queue is full\n");
        return;
    }
    pq->rear=(pq->rear+1)%5;
    pq->item[pq->rear]=num;
    //rintf("ins");
    count++;
    if(pq->front==-1)
        pq->front=0;
}

void dequeue(queue *pq)
{
    int num;
    if(count==0)
    {
        printf("The queue is empty\n");
        return;
    }
    num=pq->item[pq->front];
    printf("%d is dequeued\n",num);
    count--;
    if(pq->front==pq->rear)
        pq->front=pq->rear=-1;
    else
        pq->front=(pq->front+1)%5;
}

void display(queue q)
{
    int i;
    if(count==0)
    {
        printf("Queue is empty\n");
        return;
    }
    if(q.rear>=q.front)
    {

    for(i=q.front;i<=q.rear;i++)
    {
        printf("%d\t",q.item[i]);
    }
    }
    else
    {
        for(i=q.front;i<5;i++)
            printf("%d\t",q.item[i]);
        for(i=0;i<=q.rear;i++)
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
      printf("1.Enqueue \n2.Dequeue\n3.Display\n");
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
          default: done=0;
      }
    }
}



