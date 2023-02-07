#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

// QUEUE 
/*
Insertion from behind (insert at end fun)
Deletion from front (delete at beg fun)
*/

void enqueue(int data)
{
    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(head == NULL) ///////////////////if queue is empty
    {
        head = new_node;
    }
    else
    {
        struct node * ptr = head;
        while(ptr->next != NULL) ////////traversing till the last node
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    printf("\n%d is enqueued",data);
}

void dequeue()
{
    printf("\n%d is dequeued",head->data);
    head = head->next;
}

void display()
{
    struct node * ptr = head;
    while(ptr != NULL)
    {
        printf("|_%d_|---",ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    printf("Queue using LL Program\n");
    int stop = 0;
    while(stop != 1)
    {
        int choice, data;
        printf("\nMENU: \n1.ENQUEUE \n2.DEQUEUE \n3.DISPLAY \n4.EXIT");
        printf("\nChoice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("\nWhat element do you want to enqueue? ");
                    scanf("%d",&data);
                    enqueue(data);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: stop = 1;
                    break;        
            default: printf("Enter a valid input");        
        }
    }
    return 0;
}
