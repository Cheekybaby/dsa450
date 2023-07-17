#include <iostream>
using namespace std;

int main(){
    int arr[] = {0, 2, 1, 2, 0};
    int zero=0, one=0;
    int size = sizeof(arr)/sizeof(arr[0]);
    for (int j=0; j<size; j++){
        if (arr[j]==0){
            zero++;
        } else if (arr[j]==1) {
            one++;
        }
    }
    for (int i=0; i<zero; i++){
        arr[i]=0;
    }
    for (int i=zero; i<zero+one; i++){
        arr[i]=1;
    }
    for (int i=one+zero; i<size; i++){
        arr[i]=2;
    }

    for (int j=0; j<size; j++){
        cout << arr[j] << " ";
    }

    return 0;
}