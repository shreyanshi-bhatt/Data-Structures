// Queue Program
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX], front=-1, rear=-1;
int enqueue(int);
int dequeue();
int display();

int main()
{
    int choice, value;
    int run = 1;
    printf("Welcome to Queue Program");
    while(run == 1)
    {
        printf("\nMenu: ");
        printf("\n1.ENQUEUE");
        printf("\n2.DEQUEUE");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("\nEnter value..  ");
                    scanf("%d", &value);
                    enqueue(value);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: run = 0;
                    break;
            default: printf("\nPlease enter a valid choice.");
        }
    }
    return 0;
}

int enqueue(int val)
{
    //Queue is full
    if(rear == MAX-1)
    {
        printf("Queue is Full");
    }
    // Queue is empty
    else if(front == -1 && rear == -1)
    {
        front++;
        queue[++rear] = val;
    }
    else
    {
        queue[++rear] = val;
    }
    return 0;
}

int dequeue()
{
    //Queue is empty
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is Empty");
    }
    else if(front == rear)
    {
        printf("\nThe dequeued element is %d ", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\nThe dequeued element is %d ", queue[front]);
        front++;
    }
    return 0;
}

int display()
{
    int i;
    //Queue is empty
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("|___%d___|", queue[i]);
        }
    }
    return 0;
}
