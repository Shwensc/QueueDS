//Q.2) Circular queue with counter
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
typedef struct{

    int a[SIZE],front,rear,count; //declare count variable
}Queue;

void enqueue(Queue *q,int b)
{
        int c;  //primt count value for error checking
    if(q->count==SIZE)
    {
        printf("Stack overflow.");
        return;
    }
    q->rear=(q->rear+1)%SIZE;
    q->a[q->rear]=b;
    q->count++;
    c=q->count;
    printf("Count=%d",c);    //increment counter after assigning rear b value
    //print inserted element for error checking
    if(q->front==-1)
    {
        q->front=0;
        }  //increment front when first element is inserted.(c logic)
    
}

int dequeue(Queue *q)
{
    int b,c; //c tp print count value
    if(q->count==0)
    {
        printf("Stack underflow.");
        return -2;
    }
    b=q->a[q->front];
    q->count--;
    c=q->count;
    printf("Count=%d",c);
 
    //to return b
    if(q->front==q->rear)
    {
        q->front=q->rear=-1;  //if last element has been dequeued
    }
    else 
    q->front=(q->front+1)%SIZE;//else increment front
       return b; 

    
    
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
    q1.count=0; //set count =0
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