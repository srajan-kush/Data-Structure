#include<stdio.h>
#define MAX 4

int stack[MAX];
int top = -1;

int isFull(){
    if(top == MAX-1)
       return 1;
    else
       return 0;
}
int isEmpty(){
    if(top == -1)
      return 1;
    else
      return 0;
}
void printTop(){
    printf("%d \n",stack[top]);
}

void push(){
    if(isFull()){
        printf("Stack overflow\n");
        return;
    }
    int data;
    printf("Enter element : ");
    scanf("%d",&data);
    top = top+1;
    stack[top] = data;
}
int pop(){
    int value;
    if(isEmpty()){
        printf("Stack underflow");
        return 0;
    }
    value = stack[top];
    top = top-1;
    return value;
}

void print(){
    int i;
    if(isEmpty()){
        printf("Stack underflow\n");
        return;
    }
    for(i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

void reverse(){
    for(int i=0;i<((top+1)/2);i++){
        int rev = stack[i];
        stack[i] = stack[top-i];
        stack[top-i] = rev;
    }
}


int main(){
    int n;
  do{ 
   printf("\nChoose any operation:-\n");
   printf("1.Push\n2.Pop\n3.Display\n4.Print top element\n5.Reverse\n6.Exit\n");
   printf("Enter your choise: ");
   scanf("%d",&n);
   switch(n){
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        print();
        break;
    case 4:
        printTop();
        break;
    case 5:
        reverse();
        break;
    case 6:
        printf("Exiting the programme\n");
        break;
    default:
        printf("Enter valid operation\n");
        break;
   }
 }while(n!=6);
   return 0;
}