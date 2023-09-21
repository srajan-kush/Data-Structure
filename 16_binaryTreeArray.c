#include<stdio.h>
#include<stdlib.h>
#define max 100
int arr[max];

void insert(int,int);

void insert(int data,int index){
     if (index >= max)
    {
        printf("Tree is full. Cannot insert more elements.\n");
        return;
    }
    int data1;
    if(data == -1){
        arr[index] = data;
        return;
    }
    arr[index] = data;
    printf("Enter left  child of %d: ",data);
    scanf("%d",&data1);
    insert(data1,index*2+1);
    printf("Enter right child of %d: ",data);
    scanf("%d",&data1);
    insert(data1,index*2+2);
}
void preorder(int index){
    if(arr[index] == -1)
       return;
    printf("%d ",arr[index]);
    preorder(index*2+1);
    preorder(index*2+2);
}
void inorder(int index){
    if(arr[index] == -1)
       return;
    inorder(index*2+1);
    printf("%d ",arr[index]);
    inorder(index*2+2);
}
void postorder(int index){
    if(arr[index] == -1)
       return;
    postorder(index*2+1);
    postorder(index*2+2);
    printf("%d ",arr[index]);
}
int search(int index,int key){
    if(arr[index] == -1)
       return 0;
    if(arr[index] == key){
        return 1;
    }
    return (search(index*2+1,key)+ search(index*2+2,key));
}

void upword(int index) {
    if (arr[index * 2 + 1] == -1 && arr[index * 2 + 2] == -1) {
        arr[index] = -1;
        return;
    } else if (arr[index * 2 + 1] != -1) {
        arr[index] = arr[index * 2 + 1];
        upword(index * 2 + 1);
    } else {
        arr[index] = arr[index * 2 + 2];
        upword(index * 2 + 2);
    }
}

void delete(int index, int key) {
    if (index >= max || arr[index] == -1)
        return;
    if (arr[index] == key) {
        upword(index);
        return;
    }
    if (index * 2 + 1 < max)
        delete(index * 2 + 1, key);
    if (index * 2 + 2 < max)
        delete(index * 2 + 2, key);
}

int main(){
int choice,data;
do{
    printf("\n1.Insertion of values\n2.Deleting of value\n3.Searching of Values\n4.Display values\n5.Exit\n");
    printf("Enter choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Please Enter Values in PREORDER and NULL as -1 ------\n");
            printf("Enter Main  Root Value: ");
            scanf("%d",&data);
            insert(data,0);
            break;
        case 2:
            printf("Enter value which you want to delete: ");
            scanf("%d",&data);
            delete(0,data);
            break;
        case 3:
            printf("Enter value which you want to search: ");
            scanf("%d",&data);
            int result = search(0,data);
            if(result!=0)
               printf("Entered Value is Exist in TREE\n");
            else
                printf("Entered Value is NOT Exist in TREE\n");
            break;
        case 4:
            printf("Preorder:- ");
            preorder(0);
            printf("\n");
            printf("Inorder:- ");
            inorder(0);
            printf("\n");
            printf("Postorder:- ");
            postorder(0);
            printf("\n");
            break;
        case 5:
            printf("Exiting the programme\n");
            break;
        default:
            printf("Please enter valide choice\n");
            break;
    }
  }while(choice!=5);
  return 0;
}

