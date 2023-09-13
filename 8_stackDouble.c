#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *pre;
    struct node *next;
}*top = NULL;

int isEmpty(){
    if(top==NULL)
     return 1;
    else
      return 0;
}

void push(){
    int data;
    if(isEmpty()){
        top = malloc(sizeof(struct node*));
        printf("Enter data: ");
        scanf("%d",&data);
        top->next = NULL;
        top->pre = NULL;
        return;
    }
    struct node *newnode = malloc(sizeof(struct node*));
    printf("Enter data: ");
    scanf("%d",&data);
    newnode->data = data;
    newnode->next = top;
    top->pre = newnode;
    newnode->pre = NULL;
    top = newnode;
}

int main() {
    int choice, data;
    do {
        printf("\n1.Push\n2.Display\n3.Pop\n4.Reverse\n5.Swap\n6.Exit\n");
        printf("Enter operation: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                push();
                break;
            case 2:
                display();
                break;
            case 3:
                //
                break;
            case 4:
               // reverse();
                break;
            case 5:
               // swap(3,4);
                break;
            case 6:
                printf("Exiting the program\n");
                break;
            default:
                printf("Enter valid choice\n");
                break;
        }
    } while (choice != 6);
    return 0;
}
