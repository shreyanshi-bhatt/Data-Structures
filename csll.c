//Circular Singly Linked List (CSLL)
#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *next;
};

struct node * addToEmpty(int);
struct node * addToBeg(struct node *, int);
struct node * addAtEnd(struct node *, int);
struct node * addAtPos(struct node *, int, int);
struct node * delFirst(struct node *);
struct node * delLast(struct node *);
struct node * delAtPos(struct node *, int);
void count_elements(struct node *);
int search_element(struct node *, int);
void print_data(struct node *);

int main()
{
    printf("Welcome to CSLL");
    struct node *tail;
    tail = addToEmpty(20);
    tail = addToBeg(tail, 10);
    tail = addAtEnd(tail, 30);
    tail = addAtEnd(tail, 50);
    tail = addAtEnd(tail, 60);
    tail = addAtEnd(tail, 70);
    tail = addAtPos(tail, 40, 3);
    tail = delFirst(tail);
    tail = delLast(tail);
    tail = delAtPos(tail, 1);
    //pos to be deleted = 3
    // we wrote 3 to delete it
    //NOT like array
    print_data(tail);
    count_elements(tail);
    int element;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &element);
    int index = search_element(tail, element);
    if(index == -1)
    {
        printf("\nElement not found !");
    }
    else if(index == -2)
    {
        printf("\nCSLL is empty.");
    }
    else
    {
        printf("\nElement %d is at the position: %d",element,index);
    }
    return 0;
}

struct node * addToEmpty(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

struct node * addToBeg(struct node *tail, int data)
{
    //tail->next means head
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = tail->next;
    tail->next = newNode;
    return tail;
}

void print_data(struct node *tail)
{
    struct node *temp = tail->next;
    //do while loop
    printf("\nCSLL:");
    do
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
    while(temp != tail->next);
}

struct node * addAtEnd(struct node *tail, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
    return tail;
}

struct node * addAtPos(struct node *tail, int data, int pos)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = tail->next;
    newNode->data = data;
    // pos 3 means node 4
    while(pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    if(ptr == tail)
    {
        tail = tail->next;
    }
    return tail;
}

struct node *delFirst(struct node *tail)
{
    if(tail == NULL)
    {
        //list is empty
        return tail;
    }
    if(tail->next == tail)
    {
        //only 1 node
        free(tail);
        tail = NULL;
        return tail;
    }
    struct node *temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;
    return tail;
}
struct node *delLast(struct node *tail)
{
    if(tail == NULL)
    {
        //list is empty
        return tail;
    }
    if(tail->next == tail)
    {
        //only 1 node
        free(tail);
        tail = NULL;
        return tail;
    }
    struct node *ptr = tail->next;
    while(ptr->next != tail)
    {
        ptr = ptr->next;
    }
    ptr->next = tail->next;
    free(tail);
    tail = ptr;
    return tail;
}

struct node * delAtPos(struct node *tail, int pos)
{
    struct node *temp = tail;
    if(tail == NULL)
    {
        //list is empty
        return tail;
    }
    if(tail->next == tail)
    {
        //only 1 node
        free(tail);
        tail = NULL;
        return tail;
    }
    while(pos > 1)
    {
        temp = temp->next;
        pos--;
    }
    struct node *temp2 = temp->next;
    temp->next = temp2->next;
    //CASE : Deleting the last node
    if(temp2 == tail)
    {
        tail = temp;
    }
    free(temp2);
    temp2 = NULL;
    return tail;
}

void count_elements(struct node *tail)
{
    struct node *temp = tail->next;
    int count = 0;
    while(temp != tail)
    {
        temp = temp->next;
        count++;
    }
    count++; //to count the last node
    printf("\nThe total num of elements in the list are: %d", count);
}

int search_element(struct node *tail, int element)
{
    struct node *temp;
    int index = 0;
    if(tail == NULL)
    {
        return -2; //list is empty
    }
    temp = tail->next;
    do
    {
        if(temp->data == element)
        {
            index++;
            return index;
        }
        temp = temp->next;
        index++;
    }
    while(temp != tail->next);
    return -1;
}
