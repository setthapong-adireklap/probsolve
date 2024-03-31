#include <bits/stdc++.h>

using namespace std;

vector<int> line;

int findGroup(int n){

    vector<int> minCost(n,INT_MAX);
    minCost[0] = 0;

    int maxVal, minVal;
    for(int i = 1 ; i<n ; i++){
        maxVal = line[i];
        minVal = line[i]; 
        for(int j = 1 ; j<10 ; j++){
            if(i-j < 0){
                break;
            }
            maxVal = max(maxVal,line[i-j]);
            minVal = min(minVal,line[i-j]);
            if(i-j == 1){
                continue;
            }
            
            if(i-j-1 >= 0){
                minCost[i] = min(minCost[i],maxVal-minVal+minCost[i-j-1]);
            }
            else{
                minCost[i] = min(minCost[i],maxVal-minVal);
            }
        }
    }
    return minCost[n-1];
}

int main(){

    int n;
    cin >> n;

    int data;
    for(int i = 0 ; i<n ; i++){
        cin >> data;
        line.push_back(data);
    }
    cout << findGroup(n) << endl;

    return 0;
}