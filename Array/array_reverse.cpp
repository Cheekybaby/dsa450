#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void revArrIterative(int arr[], int start, int end){
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void revArrRecursion(int arr[], int start, int end){
    if(start>=end){
        return;
    }
    swap(arr[start],arr[end]);

    revArrRecursion(arr,start+1,end-1);
}

int main(){
    int array[] = {1,2,3,4,5};
    int size = sizeof(array)/sizeof(array[0]);
    // revArrIterative(array, 0, size-1);
    revArrRecursion(array, 0, size-1);
    
    printArray(array, size);

    return 0;
}