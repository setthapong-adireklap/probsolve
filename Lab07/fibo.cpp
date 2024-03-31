#include <bits/stdc++.h>
#define MAX_FIBO 100010
#define MODULO 199933

using namespace std;

int fiboSeq[MAX_FIBO];
int curr = 1;

int fibonacci(int n){
    
    if(n <= curr){
        return fiboSeq[n];
    }
    int l = fibonacci(n-1); 
    int r = fibonacci(n-2);
    
    if(n > curr){
        curr = n;
        fiboSeq[n] = (l+r) % MODULO;
    }

    return fiboSeq[n] ;
}

int main(){

    fiboSeq[0] = 0;
    fiboSeq[1] = 1;

    int n;
    cin >> n;
    cout << fibonacci(n) << endl;

    return 0;
}