//Binary Search Tree : BT in which left_node < parent_node < right_node
#include<stdio.h>
#include<stdlib.h>

struct bst_node
{
    int data;
    struct bst_node * left_child;
    struct bst_node * right_child;
};

struct bst_node * create(int data)
{
    struct bst_node * new_node = (struct bst_node *)malloc(sizeof(struct bst_node));
    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    return new_node;
}

void insert(struct bst_node * root,int data)
{
    // if(root==NULL)
    // {
    //     root = create(data);
    //     printf("%d inserted as root",data);
    // }
    if(data < root->data)
    {
        if(root->left_child == NULL)
        {
            root->left_child = create(data);
            printf("%d inserted",data);
        }    
        else
        {
            insert(root->left_child,data);  
            printf("%d inserted",data);
        }      
    }
    else if (data > root->data)
    {
        if(root->right_child == NULL)
        {
            root->right_child = create(data);
            printf("%d inserted",data);
        }    
        else
        {
            insert(root->right_child,data);   
            printf("%d inserted",data);
        }     
    }
    else 
        printf("\nERROR!");
}


void inOrder(struct bst_node * root) //IN-ORDER TRAVERSAL
{
    //if(root==NULL) return;
    inOrder(root->left_child);
    printf(" %d, ",root->data);
    inOrder(root->right_child);
}


int main()
{
    printf("BST Program\n");
    struct bst_node * root = create(8); 
    int stop=0;
    while(stop != 1)
    {
        int choice, data;
        printf("\n1.INSERT\n2.DISPLAY\n3.EXIT\nChoose: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data to be inserted: ");
            scanf("%d",&data);
            insert(root,data);
            break;
        case 2:
            printf("\nINORDER TRAVERSAL\n");
            inOrder(root);
            break;
        case 3:
            stop = 1;
            break;    
        default:
            break;
        }
    }
    
    return 0;
}

