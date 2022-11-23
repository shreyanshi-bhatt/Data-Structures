//Singly Linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
   int data;
   struct node* link;
};

void count_of_nodes(struct node *);
void print_data(struct node *);
void add_at_end(struct node *, int);
struct node * add_at_beg(struct node *, int);
void add_at_pos(struct node *, int, int);
struct node * del_first(struct node *);
void del_last(struct node *);
void del_at_pos(struct node **, int);
struct node *del_list(struct node *);
struct node *rev(struct node *);

int main()
{
    printf("Welcome to SLL Program");

    struct node *head = (struct node*)malloc(sizeof(struct node));

    head->data = 20;
    head->link = NULL;

    /* the lethargic way......
     struct node *current = (struct node*)malloc(sizeof(struct node));

    current->data = 20;
    current->link = NULL;

    head->link = current;

    struct node *current2 = (struct node*)malloc(sizeof(struct node));

    current2->data = 30;
    current2->link = NULL;

    head->link->link = current2;*/

    add_at_end(head, 30);
    add_at_end(head, 50);
    head = add_at_beg(head, 10);
    add_at_pos(head, 40, 4);

    //head = del_first(head);
    //del_last(head);
    //del_at_pos(&head, 1);


    //To delete SLL
    /*head = del_list(head);
    if(head == NULL)
    {
        printf("\nSLL deleted successfully.");
    }*/

    //To reverse SLL
    //head = rev(head);

    count_of_nodes(head);
    print_data(head);
    return 0;
}

void count_of_nodes(struct node *head)
{
    int count = 0;
    struct node *ptr = NULL;
    ptr = head;
    if(head == NULL)
    {
        printf("\nSLL is empty.");
    }
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    printf("\nNum of Nodes = %d \n", count);
}

void print_data(struct node *head)
{
    struct node *ptr = NULL;
    ptr = head;
    if(head == NULL)
    {
        printf("\nSLL is Empty.");
    }
    printf("\nSLL: \n");
    while(ptr != NULL)
    {
        printf("|__%d__|--->", ptr->data);
        ptr = ptr->link;
    }
}

//Inserting a node at end
void add_at_end(struct node *head, int data)
{
    struct node *ptr = NULL;
    ptr = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->link = NULL;

    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

//Inserting a node at beginning
//********function returns a pointer******//
struct node * add_at_beg(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = head;
    head = ptr;
    return head;
}

//Inserting a node at a certain position
void add_at_pos(struct node *head, int data, int pos)
{
    struct node *ptr = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    pos--;
    while(pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }
    temp->link = ptr->link;
    ptr->link = temp;
}

//Deleting the 1st node
//********function returns a pointer******//
struct node * del_first(struct node *head)
{
 if(head == NULL)
 {
     printf("SLL is empty.");
 }
 else
 {
     struct node *temp = head;
     head = head->link;
     free(temp);
 }
 return head;
}

//Deleting the last node
void del_last(struct node *head)
{
    if(head == NULL)
    {
        printf("SLL is empty.");
    }
    else if(head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        while(temp->link->link != NULL)
        {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
}

//Deleting at a specific position ############## (Doubt) ##############
//Here pos is taken according to array..... means 2nd node is pos 1
void del_at_pos(struct node **head, int pos)
{
    struct node *current = *head;
    struct node *previous = *head;
    if(*head == NULL)
    {
        printf("SLL is empty.");
    }
    else if(pos == 1)
    {
        *head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while(pos != 1)
        {
            previous = current;
            current = current->link;
            pos--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
}

//Deleting the entire SLL
//********function returns a pointer******//
struct node *del_list(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
    return head;
}

//Reverse a SLL
//********function returns a pointer******//
struct node *rev(struct node *head)
{
    struct node *prev = NULL;
    struct node *next = NULL;
    while(head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}
