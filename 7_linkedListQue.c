#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*head = NULL,*rear=NULL;

int isEmpty(){
    if(head == NULL)
       return 1;
    else 
       return 0;
}

void Enque(int data){
    struct node *newnode;
    newnode = malloc(sizeof(newnode));
    newnode->data = data;
    newnode->link = NULL;
    if(isEmpty()){
        head = newnode;
        rear = newnode;
        return;
    }
    rear->link = newnode;
    rear = rear->link;
}

int Deque(){
    struct node *temp = head;
    int data;
    if(isEmpty()){
        printf("Queue underflow\n");
        exit(1);
    }
    data = temp->data;
    head = head->link;
    free(temp);
    temp = NULL;
    return data;
}

int peek(){
    return head->data;
}

void Display(){
    struct node *temp = head;
    if(isEmpty()){
        printf("Queue underflow\n");
        exit(1);
    }
    printf("Elements are: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){
    int choice,data;
    do{
        printf("\n1.Enque\n2.Deque\n3.Display\n4.Peek element\n5.Exit\n");
        printf("Enter operation: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter element: ");
                scanf("%d",&data);
                Enque(data);
                break;
            case 2:
                data = Deque();
                printf("Deleted element is: %d",data);
                break;
            case 3:
                Display();
                break;
            case 4:
                data = peek();
                printf("Peek element is %d",data);
                break;
            case 5:
                printf("Exiting the programme\n");
                break;
            default:
                printf("Please Enter valid choice\n");
                break;
        }
    }while(choice!=5);
    return 0;
}