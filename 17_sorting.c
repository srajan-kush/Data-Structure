#include <stdio.h>

void conquer(int*, int, int, int, int);


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Merge sorting ----------------------------------------------------------------------------------------------------
void divide(int arr[], int start_index, int end_index, int n) {
    if (start_index < end_index) {
        int mid = start_index + (end_index - start_index) / 2;
        divide(arr, start_index, mid, n);
        divide(arr, mid + 1, end_index, n);
        conquer(arr, start_index, mid, end_index, n);
    }
}

void conquer(int arr[], int start_index, int mid, int end_index, int n) {
    int merge[end_index - start_index + 1];
    int idx1 = start_index;
    int idx2 = mid + 1;
    int x = 0;

    while (idx1 <= mid && idx2 <= end_index) {
        if (arr[idx1] <= arr[idx2]) {
            merge[x++] = arr[idx1++];
        } else {
            merge[x++] = arr[idx2++];
        }
    }

    while (idx1 <= mid) {
        merge[x++] = arr[idx1++];
    }

    while (idx2 <= end_index) {
        merge[x++] = arr[idx2++];
    }

    for (int i = 0, j = start_index; i < x; i++, j++) {
        arr[j] = merge[i];
    }
}



// Quick sort -------------------------------------------------------------------------------------------------------
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}


// bubble sorting ---------------------------------------------------------------------------------------------------
void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (*(arr + j) > *(arr + j+1)) 
                swap(arr + j, arr + j + 1);
        }
    }
}


// Selection sorting ---------------------------------------------------------------------------------------------
void selection_sort(int *arr , int n){
    for(int i = 0;i<n-1;i++){
        int min_index = i;
        for(int j = i+1;j<n;j++){
            if(*(arr + j) < *(arr + min_index))
               min_index = j;
        }
        if(min_index != i)
           swap(arr+i,arr+min_index);
    }
}

// insertion sorting --------------------------------------------------------------------------------------------------
void insertion_sort(int *arr , int n){
    for(int i = 1;i<n;i++){
        int temp = *(arr+i);
        int j = i-1;
        while(j >= 0 && *(arr + j) > temp){
            *(arr + j+1) = *(arr + j);
            j--;
        }
        *(arr+j+1) = temp;
    }
}


void display(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter length of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter your array elements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // bubble_sort(arr, n);
    // selection_sort(arr,n);
    // insertion_sort(arr,n);
    // divide(arr, 0, n - 1, n);
    // quick_sort(arr,0,n-1);
    display(arr, n);
    return 0;
}
