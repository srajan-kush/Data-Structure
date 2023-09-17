#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraverse(struct node* root){
    if(root==NULL)
      return;
    printf("%d ",root->data);
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}

void postorderTraverse(struct node* root){
    if(root==NULL)
      return;
    postorderTraverse(root->left);
    postorderTraverse(root->right);
    printf("%d ",root->data);
}

struct node *bst(struct node *root){
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    if(data == -1){
        return root;
    }
    root = insert(root,data);
    bst(root);
    

}

int main() {
    struct node* root = NULL;
    root = bst(root);
    inorderTraversal(root);
    printf("\n");
    preorderTraverse(root);
    printf("\n");
    postorderTraverse(root);
    printf("\n");
    return 0;
}
