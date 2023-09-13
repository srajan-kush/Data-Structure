#include <stdio.h>
#include <stdlib.h>
#define size 5

int queue[size];
int front = -1, rear = -1;

int isFull() {
    if (rear == size - 1)
        return 1;
    else
        return 0;
}

int isEmpty() {
    if (front == -1 || rear == -1)
        return 1;
    else
        return 0;
}

int peak() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        exit(1);
    } else {
        return queue[front];
    }
}

void Enque(int data) {
    if (front == -1) {
        front = front + 1;
        rear = rear + 1;
        queue[rear] = data;
        return;
    } else if (isFull()) {
        printf("Queue overflow\n");
        return;
    } else {
        queue[++rear] = data;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int deque(){
    int data;
    data = queue[front];
    for(int i =0;i<rear;i++){
        queue[i]=queue[i+1];
    }
    rear-=1;
    return data;
}

int main() {
    int choice, data;
    do {
        printf("\n1.Enque\n2.Deque\n3.peek element\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element value: ");
                scanf("%d", &data);
                Enque(data);
                break;
            case 2:
                data = deque();
                printf("Deleted element is: %d\n", data);
                break;
            case 3:
                data = peak();
                printf("Peek element: %d\n", data);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting the program\n");
                break;
            default:
                printf("Please enter a valid choice\n");
                break;
        }
    } while (choice != 5);
    return 0;
}
