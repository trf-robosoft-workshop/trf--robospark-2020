#include <stdio.h>
#include <stdlib.h>

struct {
    int data;
    struct node *left,*right;
}node;

struct node *root;

void ins (struct node *n,int val,int opt)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->left = t->right = NULL;
    if(opt==1)
    n->left=t;
    else
    n->right=t;
    printf("%d id inserted ",val);
    if(opt==1){
        printf("at the left\n");
    }
    else
    {
        printf("at the right\n");
    }
    
}

void insert(struct node *t,int x){
    if(t->data>x){
        if (t->left==NULL){
            ins(t,x,1);
        }
        else{
        insert(t->left,x);
        }
    }
    else if (t->data<x){
        if(t->right==NULL)
        {
        ins(t,x,2);
        }
        else{
        insert(t->left,x);
        }
    }
    else{
    printf("Element is Already Found");
    }
}

void inorder(struct node *p)
{
    if(p!=NULL){
        inorder(p->left);
        printf("%d\t",p->data);
        inorder(p->right);
    }
}

void preorder(struct node *p)
{
    if(p!=NULL){
        printf("%d\t",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(struct node *p){
    if(p!=NULL){
        postorder(p->left);
        postorder(p->right);
        printf("%d\t",p->data);
    }
}

main()
{
    int op,n;
    root = (struct node *)malloc(sizeof(struct node));
    printf("Enter Root Value:");
    scanf("%d",&root->data);
    root->left=root->right=NULL;
    do
    {
        printf("\tInsertion->1\n");
        printf("\tPreorder->2\n");
        printf("\tInorder->3\n");
        printf("\tPost Order->4\n");
        printf("\tExit->5\n");
        printf("Enter your choice-> ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
                printf("Enter the element to insert\n");
                scanf("%d",&n);
                insert(root,n);
            break;
        case 2:
                printf("The preorder elements are\n");
                preorder(root);
                printf("\n");
                break;
        case 3:
                printf("The inorder elements are\n");
                inorder(root);
                printf("\n");
                break;
        case 4:
                printf("The postorder elements are\n");
                postorder(root);
                printf("\n");
                break;
        case 5: 
                break;
        default:
                printf("You have entered a wrong choice\n");

        }
    } while (op!=5);
    
}