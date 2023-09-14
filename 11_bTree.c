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
}
/*
Enter data: 9
Enter data: 8
Enter data: 7
Enter data: 2
Enter data: -1
Enter data: -1
Enter data: 1
Enter data: -1
Enter data: -1
Enter data: 3
Enter data: -1
Enter data: -1
Enter data: 2
Enter data: -1
Enter data: 5
Enter data: 9
Enter data: 6
Enter data: -1
Enter data: -1
Enter data: -1
Enter data: 8
Enter data: -1
Enter data: -1
9 8 7 2 1 3 2 5 9 6 8  #preorder
2 7 1 8 3 9 2 6 9 5 8  #inorder
2 1 7 3 8 6 9 8 5 2 9  #postorder
*/