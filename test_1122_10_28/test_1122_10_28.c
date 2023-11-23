#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    int* a;
    int front;
    int rear;
    int k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->a = (int*)malloc(sizeof(int) * (k + 1));
    obj->front = 0;
    obj->rear = 0;
    obj->k = k;

    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    obj->a[obj->rear] = value;
    obj->rear++;
    obj->rear %= (obj->k + 1);

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    obj->front++;
    obj->front %= (obj->k + 1);

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->a[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->a[(obj->rear - 1 + obj->k + 1) % (obj->k + 1)];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}

int main()
{
    MyCircularQueue* obj = myCircularQueueCreate(5);
    myCircularQueueEnQueue(obj, 1);
    myCircularQueueEnQueue(obj, 2);
    myCircularQueueEnQueue(obj, 3);
    myCircularQueueEnQueue(obj, 4);
    myCircularQueueEnQueue(obj, 5);

    printf("%d\n", myCircularQueueFront(obj));
    printf("%d\n", myCircularQueueRear(obj));

    myCircularQueueFree(obj);
    return 0;
}