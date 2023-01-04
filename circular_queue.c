//Circular Queue program
// IMP FORMULA : i=(i+1)%MAX
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;
int enqueue(int);
int dequeue();
int display();

int main()
{
    printf("Welcome to Circular Queue Program\n");
    int run = 1, choice, value;
    while(run == 1)
    {
        printf("\nMenu: ");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("\nEnter value to be inserted in the queue..");
                    scanf("%d", &value);
                    enqueue(value);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: run = 0;
                    break;
            default: printf("\nPlease enter a valid choice..");
        }
    }
     return 0;
}

int enqueue(int val)
{
    //Queue is Empty
    if(rear == -1 && front == -1) // front = rear = -1
    {
        rear = front = 0;
        queue[rear] = val;
    }
    //Queue is FULL
    else if((rear+1)%MAX == front) //*********************
    {
        printf("\nQueue is Full");
    }
    else
    {
        rear = (rear+1)%MAX;  //*********************
        queue[rear] = val;
    }
    return 0;
}

int dequeue()
{
    //Queue is empty
    if(front == -1 && rear == -1)//front = rear = -1
    {
        printf("\nThe Queue is Empty.");
    }
    else if(front == rear)//front = rear = 0 .....Only 1 element in queue
    {
        printf("\nThe dequeued element is %d ", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("\nThe dequeued element is %d ", queue[front]);
        front = (front+1)%MAX;  //*********************
    }
    return 0;
}

int display()
{
    int i = front;
    //Queue is empty
    if(rear == -1 && front == 1)
    {
        printf("Queue is empty");
    }
    else
    {
        while(i != rear)//while loop is used while displaying in circular loop
        {
            printf("___%d___", queue[i]);
            i = (i+1)%MAX;  //*********************
        }
        printf("___%d___", queue[i]);
    }
    return 0;
}

