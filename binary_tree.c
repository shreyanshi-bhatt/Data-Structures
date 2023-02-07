#include<stdio.h>
#include<stdlib.h>

//BT : Num_of_child_nodes = (0,1,2)
//Not more than 2 child nodes

struct bt_node ///create struct bt_node
{
    struct bt_node * left_child;
    int data;
    struct bt_node * right_child;
};

struct bt_node * create(int data) //To create a new node
{
    struct bt_node * new_node = (struct bt_node *)malloc(sizeof(struct bt_node));
    new_node->data = data;
    new_node ->left_child = NULL;
    new_node->right_child = NULL;

    return new_node;
}

void insertRight(struct bt_node * root,int data) //insert on right side
{
    root->right_child = create(data);
}

void insertLeft(struct bt_node * root,int data) // insert on left side
{
    root->left_child = create(data);
}

void preOrder(struct bt_node * root) //PRE-ORDER TRAVERSAL
{
    if(root==NULL) return;
    printf(" %d, ",root->data);
    preOrder(root->left_child);
    preOrder(root->right_child);
}

void inOrder(struct bt_node * root) //IN-ORDER TRAVERSAL
{
    if(root==NULL) return;
    inOrder(root->left_child);
    printf(" %d, ",root->data);
    inOrder(root->right_child);
}

void postOrder(struct bt_node * root) //POST-ORDER TRAVERSAL
{
    if(root==NULL) return;
    postOrder(root->left_child);
    postOrder(root->right_child);
    printf(" %d, ",root->data);
}

int main() //main fun
{
    printf("Binary Tree Program\n");
    struct bt_node * root = create(10); //////create root in main
    insertLeft(root,20);
    insertRight(root,30);
    insertLeft(root->left_child,40);
    insertRight(root->left_child,50);
    insertLeft(root->right_child,60);
    insertRight(root->right_child,70);

    printf("\nPreOrder Traversal");
    preOrder(root);
    printf("\nInOrder Traversal");
    inOrder(root);
    printf("\nPostOrder Traversal");
    postOrder(root);

    return 0;
}