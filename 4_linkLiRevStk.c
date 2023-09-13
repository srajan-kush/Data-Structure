#include<stdio.h>
#include<stdlib.h>

struct stack{
   int data;
   struct stack *link;
};

int isEmpty(struct stack *top){
    if(top == NULL)
       return 1;
    else
       return 0;
}

void push(int data, struct stack** top1){
    struct stack *newnode;
    newnode = malloc(sizeof(newnode));
    if(newnode == NULL){
        printf("Stack overflow\n");
        exit(1);
    }
    newnode->data = data;
    newnode->link = NULL;

    newnode->link = *top1;
    *top1 = newnode;
}

int pop(struct stack** top){
    struct stack *temp;
    temp = *top;
    if(isEmpty(temp)){
        printf("Stack underflow\n");
        exit(1);
    }
    int data;
    data = temp->data;
    *top = (*top)->link;
    free(temp);
    temp = NULL;
    return data;   
}

void display(struct stack** top){
    struct stack *temp;
    temp = *top;
    if(isEmpty(*top)){
        printf("Stack underflow\n");
        return;
    }
    printf("Stack element are: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void reverseStack(struct stack** top){
    struct stack *top1 = NULL;
    struct stack *top2 = NULL;
    while(*top != NULL){
        push(pop(top),&top1);
    }
    while(top1!=NULL){
        push(pop(&top1),&top2);
    }
     while(top2!=NULL){
        push(pop(&top2),top);
    }
}

int main(){
    struct stack *top= NULL;
    int choice,data;
    do{
        printf("\n1.Push\n2.Pop\n3.Reverse elements\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter element: ");
                scanf("%d",&data);
                push(data,&top);
                break;
            case 2:
                data = pop(&top);
                printf("Deleted element is: %d\n",data);
                break;
            case 3:
                reverseStack(&top);
                display(&top);
                break;
            case 4:
                display(&top);
                break;
            case 5:
                printf("Exiting the programme\n");
                break;
            default:
                printf("Please enter valid choice\n");
                break;
        }
    }while(choice!=5);
}