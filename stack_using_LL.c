#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

// STACK
/*
Insertion from top (insert at beg fun)
Deletion from top (delete at beg fun)
*/

void push(int);
void pop();
void display();

int main()
{
    printf("Stack using linked list\n");
    int stop = 0;
    while(stop != 1)
    {
        int choice, data;
        printf("MENU: \n1.PUSH \n2.POP \n3.DISPLAY \n4.EXIT");
        printf("\nChoice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("\nWhat element do you want to push?");
                    scanf("%d",&data);
                    push(data);
                    break;
            case 2: pop();
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

void push(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("\n %d is pushed on the stack",data);
}

void pop()
{
    struct node *ptr = head;
    head = head->next;
    int pop_value = ptr->data;
    printf("\n%d is popped",pop_value);
}

void display()
{
    struct node* ptr = head;
    while(ptr != NULL) {
        printf("|___%d___|\n", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
