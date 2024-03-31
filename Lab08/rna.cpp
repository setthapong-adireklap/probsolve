#include <bits/stdc++.h>
#define MAX_SIZE 201

using namespace std;

int matching[MAX_SIZE][MAX_SIZE];
int result = INT_MIN;

void findMaximumMatching(string &s){

    int n = s.size();
    // initialize
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <= i+4 ; j++){
            if(j>=n){
                break;
            }
            matching[i][j] = 0;
        }
    }
    for(int i = 0 ; i<n ; i++){
        for(int j = i+5 ; j<n ; j++){
            if(j >= n){
                break;
            }
            
        }
    }

}

int main(){

    string rnaSeq;
    cin >> rnaSeq;
    
    findMaximumMatching(rnaSeq);

    cout << result << endl;

    return 0;
}