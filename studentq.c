#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct Student {
    int rollNumber;
    char name[50];
};

struct Queue {
    struct Student data[MAX_QUEUE_SIZE];
    int front, rear;
};

void initQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueEmpty(struct Queue *queue) {
    return queue->front == -1;
}

int isQueueFull(struct Queue *queue) {
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

void enqueue(struct Queue *queue, struct Student student) {
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isQueueEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }

    queue->data[queue->rear] = student;
    printf("Enqueued: Roll Number %d, Name: %s\n", student.rollNumber, student.name);
}

struct Student dequeue(struct Queue *queue) {
    struct Student emptyStudent = {-1, "Empty"};

    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return emptyStudent;
    }

    struct Student dequeuedStudent = queue->data[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }

    return dequeuedStudent;
}

int main() {
    struct Queue studentQueue;
    initQueue(&studentQueue);

    struct Student s1 = {101, "Alice"};
    struct Student s2 = {102, "Bob"};
    struct Student s3 = {103, "Charlie"};

    enqueue(&studentQueue, s1);
    enqueue(&studentQueue, s2);
    enqueue(&studentQueue, s3);

    struct Student dequeuedStudent = dequeue(&studentQueue);
    printf("Dequeued: Roll Number %d, Name: %s\n", dequeuedStudent.rollNumber, dequeuedStudent.name);

    return 0;
}
