#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
} *top = NULL;

int isEmpty(){
    if(top == NULL)
       return 1;
    else
       return 0;
}

void push() {
    int data;
    printf("Enter element: ");
    scanf("%d", &data);
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Stack overflow");
        exit(1);
    }
    newnode->data = data;
    newnode->link = top;
    top = newnode;
}

int pop(){
    struct node *temp;
    int val;
    temp = top;
    if(isEmpty()){
        printf("Stack is underflow\n");
        exit(1);
    }
    top = top->link;
    val = temp->data;
    free(temp);
    temp = NULL;
    return val;

}

void reverse(){
    struct node *prev = NULL;
    struct node *curr = top;
    struct node *next = NULL;
    while(curr!=NULL){
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
        
    }
    top = prev;
}

void display() {
    struct node* temp;
    temp = top;
    if(isEmpty()){
        printf("Stack is underflow\n");
        return;
    }
    printf("The stack elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int choice, data;
    do {
        printf("\n1.Push\n2.Display\n3.Pop\n4.Reverse\n5.Swap\n6.Exit\n");
        printf("Enter operation: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                display();
                break;
            case 3:
                data = pop();
                printf("Deleted element is: %d\n",data);
                break;
            case 4:
                reverse();
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
