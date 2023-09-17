#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *create(){
    int data;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&data);
    if(data == -1)
      return 0;
    newnode->data = data;
    newnode->next = create();
    return newnode;
}

int main(){
    struct node *list1;
    list1 = create();
    while(list1 != NULL){
        printf("%d ",list1->data);
        list1 = list1->next;
    }
}