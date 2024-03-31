#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
long long totalInversion = 0;

void findAcross(int l, int m, int r){
    vector<int> arrL,arrR;
    int sizeL = m-l+1 ,sizeR = r-m;

    for(int i = 0 ; i<sizeL ; i++){
        arrL.push_back(arr[i+l]);
    }
    for(int i = 0 ; i<sizeR ; i++){
        arrR.push_back(arr[i+m+1]);
    }
    sort(arrL.begin(),arrL.end());
    sort(arrR.begin(),arrR.end());

    long long total = 0;
    int curr = 0;

    for(int i = 0 ; i<sizeL ; i++){
        while(curr < sizeR && arrL[i] > arrR[curr]){
            total++;
            curr++;
        }
        totalInversion += total;
    }
}

void findTotalInversion(int l, int r){
    if(l >= r){
        return;
    }
    else if(r-l+1 == 2){
        if(arr[l] > arr[r]){
            totalInversion++;
            return;
        }
    }
    int m = l + (r-l)/2;
    findTotalInversion(l,m);
    findTotalInversion(m+1,r);

    findAcross(l,m,r);
}

int main(){

    int n;
    cin >> n;

    int data;
    for(int i = 0 ; i<n ; i++){
        cin >> data;
        arr.push_back(data);
    }
    findTotalInversion(0,n-1);
    cout << totalInversion << endl;

    return 0;
}