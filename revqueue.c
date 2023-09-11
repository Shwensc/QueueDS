/* logic: for enqueue, push elements in stack1 , for dequeue,pop elemnts from stack 1 & push that into stack 2,
tos of stack 2 is deleted element, we do this because q has insertion & deletion at both ends*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
typedef struct{
    int a[SIZE],tos;
}Stack;

typedef struct{
    Stack s1,s2;
}Queue;

int is_empty(Stack *s) {
    return s->tos == -1;
}

int is_full(Stack *s) {
    return s->tos == SIZE - 1;
}

void push(Stack *s, int a)
{
    if(s->tos==SIZE-1)
    {
        printf("Stack overflow");
        return;
    }
    s->a[++s->tos]=a;
    printf("\nInserted element =%d",a);

}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->a[s->tos--];
}
void enqueue(Queue *q,int a)
{
    push((&(q->s1)),a);  //push element into stack1, use call by address
}



int dequeue(Queue *q)
{
    if(is_empty(&(q->s2)))
    {
        {
        while(!is_empty(&(q->s1)))
        push(&(q->s2),pop(&(q->s1)));
        }
    }
    return pop(&(q->s2));
}

int main()
{
    Queue q1;
    q1.s1.tos=-1; //setting tos
    q1.s2.tos=-1;
    int x,option;
    char ch;
    do {
        printf("1 to Enqueue, 2 to Dequeue, 3 to display:\n");
        scanf("%d", &option);

        switch (option) 
        {
            case 1:printf("Enter element to be enqueued: ");
                    scanf("%d",&x);
                    enqueue(&q1,x);
                    break;
            case 2: x=dequeue(&q1);
                    printf("Dequeued elemnt=%d",x);
                    break;
                
        }
        printf("Continue(y/Y)?");
        scanf(" %c",&ch);
    } while (ch=='y' || ch=='Y');

    return 0;
}
