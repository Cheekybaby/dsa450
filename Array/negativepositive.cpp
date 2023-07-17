#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

void rearrange(int arr[], int n){
    int j=0;
    for (int i=0; i<n; i++){
        if (arr[i]<0){
            if (i!=j){
                swap(arr[i], arr[j]);
            }
            j++;
        }
    }
}

void swapping(int arr[], int left, int right){
    // condition for loop to terminate
    while (left<=right){
        // condition to check if the left and the right elements are negative
        if(arr[left]<0 && arr[right]<0){
            left++;
        } else if (arr[left]>0 && arr[right]<0){
            swap(arr[left], arr[right]);
            left++;
            right--;
        } else if (arr[left]>0 && arr[right]>0){
            right--;
        } else {
            left++;
            right--;
        }
    }
}

void dnf(int arr[], int low, int high){
    while(low<high){
        if(arr[low]<0){
            low++;
        } else if (arr[high]>0){
            high--;
        } else {
            swap (arr[low], arr[high]);
        }    
    }
}

int main(){
    int arr[] ={-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);

    // sort(arr, arr+size);
    // rearrange(arr, size);
    // swapping(arr, 0, size-1);
    dnf(arr, 0, size-1);

    printArray(arr, size);
    return 0;
}