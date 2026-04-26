#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    queue[++rear] = x;
}

int dequeue()
{
    if (front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

int size()
{
    return rear - front + 1;
}

void push(int x)
{
    enqueue(x);
}

int pop()
{
    if (size() == 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    int n = size();
    while (n > 1)
    {
        int temp = dequeue();
        enqueue(temp);
        n--;
    }
    return dequeue();
}

void display()
{
    if (size() == 0)
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    printf("Popped: %d\n", pop());
    display();
    push(40);
    display();
    return 0;
}