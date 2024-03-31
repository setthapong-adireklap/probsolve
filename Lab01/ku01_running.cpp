#include <iostream>

using namespace std;

int main(){

    int n, k, x;
    int fastest = 0;
    cin >> n >> k;
    
    int theRest = n;
    int* timeArr = new int[n];
    for(int i = 0 ; i<n ; i++){
        cin >> x;
        timeArr[i] = x;
        fastest = (x < timeArr[fastest])? i : fastest;
    }

    long long check = (long long)timeArr[fastest]*(long long)k;
    long long temp;
    for(int i = 0 ; i<n ; i++){
        if(i != fastest){
            temp = (long long)timeArr[i]*(long long)(k-1);
            if((long long)check <= (long long)temp){
                theRest -= 1;
            }
        }
    }

    cout << theRest << endl;

    return 0;
}