//Q.1) Circular queue without counter
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
typedef struct{

    int a[SIZE],front,rear;
}Queue;
int isEmpty(Queue *q)  //call by adress 
{
    return q->front==-1; //check if queue is empty
}
int isFull(Queue *q)
{
return (q->rear+1)%SIZE == q->front; //check if queue is full
}
void enqueue(Queue *q,int b)
{
    if(isFull(q))
    {
        printf("Stack overflow.");
        return;
    }
    q->rear=(q->rear+1)%SIZE;
    q->a[q->rear]=b; //increment rear before assigning it b value
    //print inserted element for error checking
    if(q->front==-1)
    {
        q->front=0;
        }  //increment front when first element is inserted.(c logic)
    
}

int dequeue(Queue *q)
{
    int b;
    if(isEmpty(q))
    {
        printf("Stack underflow.");
        return -2;
    }
    b=q->a[q->front];
    return b; //to return b
    if(q->front==q->rear)
    {
        q->front=q->rear=-1;  //if last element has been dequeued
    }
    else q->front=(q->front+1)%SIZE;//else increment front

    
    
}

void display(Queue q)
{
    for(int i=q.front;i<=q.rear;i=(i+1)%SIZE)
    {
        printf("%d\t",q.a[i]); //display contenets of queue
    }
}
int main()
{
    Queue q1;
    q1.front=-1;
    q1.rear=-1; //setting front and rear counter
    char ch;//ask user for y or n to continue
    int choice,element;
    do{

        printf("Enter 1 for enqueue,2 for dequeue, 3 for display: ");
        scanf("%d",&choice);
        switch(choice) //switch case for menu driven code.
        {
            case 1:printf("Enter element to be inserted: ");
                    scanf("%d",&element);
                    enqueue(&q1,element); //pass element to queue
                
                    break;
            case 2: element=dequeue(&q1);
                    printf("Popped element=%d",element); //print deleted element
                    break;
            case 3:display(q1); //display queue from front->rear
                    break;
        }
        printf("Continue?(y/Y)");
        scanf(" %c",&ch); //space before %c to avoid newline character from previous entry

    }while(ch=='y' || ch=='Y');

    return 0;
}