#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int x) { stack1[++top1] = x; }
int pop1() { return top1 == -1 ? -1 : stack1[top1--]; }

void push2(int x) { stack2[++top2] = x; }
int pop2() { return top2 == -1 ? -1 : stack2[top2--]; }

void enqueue(int x) { push1(x); }

int dequeue()
{
    if (top2 == -1)
    {
        while (top1 != -1)
            push2(pop1());
    }
    if (top2 == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    return pop2();
}

void display()
{
    for (int i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);
    for (int i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    enqueue(40);
    display();
    return 0;
}