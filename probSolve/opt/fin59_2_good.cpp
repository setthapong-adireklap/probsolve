#include <bits/stdc++.h>

using namespace std;

int dataSet[20][20];
int n,m,xRes,yRes;

int findAVG(int y, int x){
    int total = 0;
    int ref = dataSet[y][x];
    for(int i = 0 ; i<n ; i++){
        if(i == y){
            continue;
        }
        total += abs(ref-dataSet[i][x]);
    }
    for(int i = 0 ; i<m ; i++){
        if(i == x){
            continue;
        }
        total += abs(ref-dataSet[y][i]);
    }
    return total;
}

int main(){

    cin >> n >> m;
    
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            cin >> dataSet[i][j];
        }
    }

    int minVal = INT_MAX;
    int tmp;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            tmp = findAVG(i,j);
            if(tmp < minVal){
                minVal = tmp;
                yRes = i;
                xRes = j;
            }
        }
    }
    cout << dataSet[yRes][xRes] << endl;

    return 0;
}