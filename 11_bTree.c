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
int* inorderTraversal(struct node* root, int* returnSize){
      if(root == NULL){
          return returnSize;
      }
      inorderTraversal(root->left,returnSize);
      static int i = 0;
      *(returnSize+i) = root->data;
      i = i+1;
      inorderTraversal(root->right,returnSize);
}

int fun(struct node* head){
    
    if(head==NULL){
        return 0;
    }
    if(head->left==NULL && head->right==NULL){
        return 1;
    }
    return (fun(head->right)+fun(head->left));
}

int main(){
    struct node *root;
    root = NULL;
    root = create();
    int a[20];
    int *b = inorderTraversal(root,&a);
    for(int i =0;i<3;i++){
        printf("%d ",*(b+i));
    }
    


}