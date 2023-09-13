#include<stdio.h>
#include<stdlib.h>
#define size 5

int arr[size];
int front = -1, rear = -1;

int isEmpty(){
    if(rear == -1 || front == -1)
        return 1;
    else 
        return 0;
}

int isFull(){
    if((rear+1)%size == front)
       return 1;
    else
       return 0;
}

void Enque(int data){
    if(isEmpty()){
        front=0;
        rear=0;
        arr[front] = data;
        return;
    }
    if(isFull()){
        printf("Queue overflow\n");
        return;
    }
    rear = (rear + 1) % size;  
    arr[rear] = data;
}

int deque(){
    int data;
    if(isEmpty()){
        printf("Queue underflow\n");
        exit(1);
    }
    data = arr[front];
    if(front==rear){
        front = -1;
        rear = -1;
        return data;
    }
    front = (front+1)%size ;
    return data;
}

void Display(){
    int i = front;
    if(isEmpty()){
        printf("Queue underflow\n");
        return;
    }
    printf("Elements are: ");
    while(i != rear){
        printf("%d ",arr[i]);
        i = (i+1)%size;
    }
    printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    int choice,data;
    do{
        printf("\n1.Enque\n2.Deque\n3.Display\n4.exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter element: ");
                scanf("%d",&data);
                Enque(data);
                break;
            case 2:
                data = deque();
                printf("Deleted element is: %d",data);
                break;
            case 3:
                Display();
                break;
            case 4:
                printf("Exiting the programme\n");
                break;
            default:
                printf("Enter valid number\n");
                break;
        }
    }while(choice != 4);
    return 0;
}