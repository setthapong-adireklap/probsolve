#include <iostream>

using namespace std;

int find_max_round(int* nextPerson,int* status,int n){
    int temp, check;
    int round = 0;
    for(int i=0 ; i<n ; i++){
        if(!status[i]){
            temp = nextPerson[i];
            check = 1;
            while(i != temp){
                temp = nextPerson[temp];
                check++;
            }
        }
        round = (check > round)? check : round;
    }
    return round;
}

int main(){

    int n, x;
    cin >> n;
    int* status = new int[n];
    int* nextPerson = new int[n];

    for(int i=0 ; i<n ; i++){
        cin >> x;
        status[i] = 0;
        nextPerson[i] = x-1;
    }
    cout << find_max_round(nextPerson,status,n) << endl;

    return 0;
}