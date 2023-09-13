#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack *link;
};

int isEmpty(struct stack *top) {
    if (top == NULL)
        return 1;
    else
        return 0;
}

struct stack* push(struct stack *top, int data) {
    struct stack *newnode;
    newnode = malloc(sizeof(newnode));
    if (newnode == NULL) {
        printf("Stack overflow\n");
        exit(1);
    }
    newnode->data = data;
    newnode->link = NULL;

    newnode->link = top;
    top = newnode;
    return top;
}

struct stack* pop(struct stack* top){
    struct stack *temp;
    if(isEmpty(top)){
        printf("Stack underflow");
        exit(1);
    }
    temp = top;
    top = top->link;
    return temp;
}

void display(struct stack* top) {
    struct stack *temp;
    temp = top;
    if (isEmpty(top)) {
        printf("Stack underflow.\n");
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
    struct stack* temp;
    struct stack *top = NULL;
    struct stack *top1 = NULL;
    struct stack *top2 = NULL;
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    temp = pop(top);
    top = top->link;
    top1 = push(top1,temp->data);
    display(top);
    display(top1);
    return 0;
}
