#include <iostream>

using namespace std;

void decodeY(int* arr, int n){
    int check = n;
    for(int i = 0 ; i<n ; i++){
        if(arr[i] < check){
            check = arr[i]; 
            arr[i] = 0;
        }
        else if(arr[i] > check){
            check = arr[i]; 
            arr[i] = 1;
        }
    }
}

void decodeZ(int* arr, int n){
    int check = arr[0];
    for(int i = 1 ; i<n ; i++){
        if(2*check+check+1 == arr[i]){
            arr[i] = check+1;
            check = arr[i];
        }
        else{
            arr[i] = check-1;
            check = arr[i];
        }
    }
    decodeY(arr,n);
}

void printRes(int* arr, int n){
    for(int i = 0 ; i<n ; i++){
        cout << arr[i] << "\n";
    }
}

int main(){

    int n, m, x;
    cin >> n >> m;
    
    int* arr = new int[n]; 
    for(int i = 0 ; i < n ; i++){
        cin >> x;
        arr[i] = x;
    }

    if(m == 1){
        decodeY(arr,n);
    }
    else if(m == 2){
        decodeZ(arr,n);
    }
    printRes(arr,n);

    return 0;
}