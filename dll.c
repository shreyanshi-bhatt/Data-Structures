//DLL
#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node *prev;
struct node *next;
};

struct node* addToEmpty(struct node *, int);
struct node * addAtBeg(struct node*, int);
void addAtEnd(struct node*, int);
void addAtPos(struct node *, int, int);
struct node * delFirst(struct node *);
struct node * delLast(struct node *);
struct node * delAtPos(struct node *, int);
struct node * rev(struct node *);
void print_data();

int main()
{
    printf("Welcome to DLL program");
    struct node *head = NULL;
    //OR
    //struct node *head = NULL;
    //head = (struct node*)malloc(sizeof(struct node));
    /*head->data = 10;
    head->prev = NULL;
    head->next = NULL;*/

    head = addToEmpty(head, 20);

    //printf("\n",head->next); *****Nothing gets printed

    /*struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = 20;
    new_node->prev = head;
    new_node->next = NULL;

    head->next = new_node;
    printf("\n%d", new_node->data);*/

    head = addAtBeg(head, 10);
    addAtEnd(head, 30);
    addAtPos(head, 40, 3);
    addAtEnd(head, 50);
    //To delete nodes
    /*head = delAtPos(head, 1);
    head = delFirst(head);
    head = delLast(head);*/
    //head = delAtPos(head, 0);....deletes the full list
    head = rev(head);
    print_data(head);

    return 0;
}

struct node* addAtBeg(struct node *head, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

void print_data(struct node *head)
{
    struct node *temp;
    temp = head;
    if(head == NULL)
    {
        printf("\n DLL is empty.");
    }
    printf("\nDLL:");
    while(temp != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}

struct node* addToEmpty(struct node *head, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

//To traverse and stop on the last node : use while(temp->next != NULL) ... To include the last node: use while(temp != NULL)
void addAtEnd(struct node *head, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
}

void addAtPos(struct node *head, int data, int pos)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr = head;
    temp->data = data;
    //To reach at one node b4 the desired pos
    ////Here pos is taken according to array..... means 2nd node is pos 1
    while(pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;
}

struct node * delFirst(struct node *head)
{
    struct node *temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    head->prev = NULL;
    return head;
}

struct node * delLast(struct node *head)
{
    struct node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    temp = NULL;
    return head;
}

struct node *delAtPos(struct node *head, int pos)
{
    ////Here pos means 2nd node is pos 2
    struct node *ptr = head;
    struct node *temp = NULL;
    if(pos == 1)
    {
        head = delFirst(head);
        return head;
    }
    while(pos > 1)
    {
        ptr = ptr->next;
        pos--;
    }
    if(ptr->next == NULL)
    {
        delLast(head);
    }
    else
    {
        temp = ptr->prev;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        free(ptr);
        ptr = NULL;
    }
    return head;
}
struct node * rev(struct node *head)
{
    //*******Doubt*******
    struct node *ptr1 = head;
    struct node *ptr2 = ptr1->next;
    ptr1->next = NULL;
    ptr1->prev = ptr2;
    while(ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    return head;
}
