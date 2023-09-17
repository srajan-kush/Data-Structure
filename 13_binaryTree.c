#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(){
    int data;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&data);
    if(data == -1){
        return 0;
    }
    newnode->data = data;
    newnode->left = create();
    newnode->right = create();
    return newnode;
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
    struct node *root;
    root = NULL;
    root = create();
    preorderTraverse(root);
    printf("\n");
    inorderTraverse(root);  
    printf("\n");
    postorderTraverse(root);
    return 0;
}