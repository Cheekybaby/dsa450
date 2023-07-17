#include <iostream>
#include <algorithm>

using namespace std;

struct Pair {
    int min;
    int max;
};

Pair sortMinMax(int arr[], int n){
    Pair minmax; // make a pair
    sort(arr, arr+n); // sort the array
    minmax.min = arr[0]; // assigning the minimum element to the min
    minmax.max = arr[n-1]; // assigning the maximum element to the max

    return minmax;
}

Pair linearMinMax(int arr[], int n){
    Pair minmax;
    int i;

    // if there is only one element present in the array
    if (n==1){
        minmax.min = arr[0];
        minmax.max = arr[0];
        return minmax;
    }

    // if there are more than one element
    // initialise min and max
    if (arr[0]>arr[1]){
        minmax.min = arr[1];
        minmax.max = arr[0];
    } else {
        minmax.min = arr[0];
        minmax.max = arr[1];
    }

    // start from the 3rd element and compare it with both min and max, update min and max if a 
    // a new min or max is found
    for (int i=2; i<n; i++){
        if(arr[i]>minmax.max){
            minmax.max = arr[i];
        } else if(arr[i]<minmax.min){
            minmax.min = arr[i];
        }
    }
    return minmax;
}

Pair tournamentMinMax(int arr[], int low, int high){
    Pair minmax, left, right;

    // If there is only one element
    if (low==high){
        minmax.min = arr[0];
        minmax.max = arr[0];
        return minmax;
    }

    // If there are two elements
    if (high==low+1){
        if(arr[low]>arr[high]){
            minmax.min = arr[high];
            minmax.max = arr[low];
        } else {
            minmax.min = arr[low];
            minmax.max = arr[high];
        }
        return minmax;
    }

    // if there are more than two elements
    int mid = (low+high)/2; // find the mid point of the array
    left = tournamentMinMax(arr, low, mid-1); // recursively find the min and max in left subarray
    right = tournamentMinMax(arr, mid, high); // recursively find the min and max in right subarray

    // compare minimum of two parts
    if (left.min < right.min){
        minmax.min = left.min;
    } else {
        minmax.min = right.min;
    }

    // compare maximum of two parts
    if (left.max > right.max){
        minmax.max = left.max;
    } else {
        minmax.max = right.max;
    }

    return minmax;
}

Pair pairMinMax(int arr[], int n){
    Pair minmax;
    int i; // points the starting index of comparison

    // if the number of elements in the array is odd
    if (n%2){
        minmax.min = arr[0];
        minmax.max = arr[0];
        i=1;
    } else { // if the number of elements in the array is even
        if (arr[0]>arr[1]){
            minmax.min = arr[1];
            minmax.max = arr[0];
        } else {
            minmax.min = arr[0];
            minmax.max = arr[1];
        }
        i=2;
    }
    
    // loop through the array comparing in pairs
    while (i<n-1){
        if(arr[i]>arr[i+1]){
            if(arr[i+1]<minmax.min){
                minmax.min = arr[i+1];
            }
            if (arr[i]>minmax.max){
                minmax.max = arr[i];
            }
        } else {
            if (arr[i]<minmax.min){
                minmax.min = arr[i];
            }
            if (arr[i+1]>minmax.max){
                minmax.max = arr[i+1];
            }
        }
        i+=2;
    }
    return minmax;
}

int main(){
    int arr[] = {3,5,4,1,9,10,11};
    int size = sizeof(arr)/sizeof(arr[0]);

    // Pair minmax = sortMinMax(arr, size); // using the sorting method
    // Pair minmax = linearMinMax(arr, size);
    // Pair minmax = tournamentMinMax(arr, 0, size-1);
    Pair minmax = pairMinMax(arr, size);

    cout << "Maximum element of the array: " << minmax.max << endl;
    cout << "Minimum element of the array: " << minmax.min << endl;

    return 0;
}