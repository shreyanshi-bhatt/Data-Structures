//Stack Program
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX], top = -1;
int push(int);
int pop();
int display();

int main()
{
    int choice, value;
    int run = 1;
    printf("Welcome to Stack program\n");
    while(run == 1)
    {
        printf("\nMENU: ");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("\nEnter value to be pushed onto the stack..  ");
                    scanf("%d", &value);
                    push(value);
                    break;
            case 2: pop();
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

int push(int val)
{
    if(top == MAX - 1)
    {
        printf("\nStack Overflow..");
    }
    else
    {
        stack[++top] = val;
        printf("\n %d has been pushed on the stack successfully", val);
    }
    return 0;
}

int pop()
{
    if(top == -1)
    {
        printf("\nStack underflow..");
    }
    else
    {
        top--;
    }
    return 0;
}

int display()
{
    int i;
    if(top == -1)
    {
        printf("\nStack is empty..");
    }
    else
    {
        for(i=0;i<=top;i++)
        {
            printf("\n|______%d______|", stack[i]);
        }
    }
    return 0;
}
