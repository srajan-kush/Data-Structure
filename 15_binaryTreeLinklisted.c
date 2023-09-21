#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

// Question1_a---// Creating a binary tree

struct node *create(){
    int data;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&data);
    if(data == -1)
       return 0;
    newnode->data = data;
    newnode->left = create();
    newnode->right = create();
    return newnode;
}

//question1_b.... Deleting of element ---------------
void upward(struct node* root,int data){
    if(root == NULL)
       return;
    if(root->left != NULL){
        while(root->left->left != NULL){
            root->data = root->left->data;
            root = root->left;
        }
        root->data = root->left->data;
        root->left = NULL;
        return;
    }else if(root->right != NULL){
        while(root->right->right != NULL){
            root->data = root->right->data;
            root = root->right;
        }
        root->data = root->right->data;
        root->right = NULL;
        return;
    }else{
         return;
    }
}

    
struct node *delete(struct node *root, int data){
    if(root == NULL)
       return 0;
    if(data == root->data){
        upward(root,root->data);
        return NULL;
    }
    delete(root->left,data);
    delete(root->right,data);
    return root;
}

// Question1_c ----// Searching of element given by user
int isexist(struct node *root, int data){
    if(root == NULL){
       return 0;
       }
    else if(data == root->data){
        return 1;
    }
    return isexist(root->left,data)+isexist(root->right,data);   
}
void search(struct node *root, int data){
    int flag = isexist(root,data);
    if(flag != 0)
       printf("Element is EXIST in Binary Tree\n");
    else
       printf("Element is NOT EXIST in Binary Tree\n");
}

void preorderTraverse(struct node* root){
    if(root==NULL)
      return;
    printf("%d ",root->data);
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}
void inorderTraverse(struct node* root){
    if(root==NULL)
      return;
    inorderTraverse(root->left);
    printf("%d ",root->data);
    inorderTraverse(root->right);
}

void postorderTraverse(struct node* root){
    if(root==NULL)
      return;
    postorderTraverse(root->left);
    postorderTraverse(root->right);
    printf("%d ",root->data);
}

int main(){
  int choice,data;
  struct node *root = NULL;
  do{
    printf("\n1.Insertion of values\n2.Deleting of value\n3.Searching of Values\n4.Display values\n5.Exit\n");
    printf("Enter choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Please Enter Values in PREORDER and NULL as -1 ------\n");
            root = create();
            break;
        case 2:
            printf("Enter value which you want to delete: ");
            scanf("%d",&data);
            delete(root,data);
            break;
        case 3:
            printf("Enter value which you want to search: ");
            scanf("%d",&data);
            search(root,data);
            break;
        case 4:
            printf("Preorder:- ");
            preorderTraverse(root);
            printf("\n");
            printf("Inorder:- ");
            inorderTraverse(root);
            printf("\n");
            printf("Postorder:- ");
            postorderTraverse(root);
            printf("\n");
            break;
        case 5:
            printf("Exiting the programme\n");
            break;
        default:
            printf("Please enter valide choice\n");
            break;
    }
  }while(choice!=5);
  return 0;
}