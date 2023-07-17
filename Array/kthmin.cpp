#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int arr[] = {7, 10, 4, 20, 15};
    int k=4;
    int size  = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr+size);

    cout << "The kth minimum element of the array is: " << arr[k-1];

    return 0;
}