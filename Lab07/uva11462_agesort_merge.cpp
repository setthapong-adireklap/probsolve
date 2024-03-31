#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

void merge(int l, int m, int r){
    int sizeL = m-l+1;
    int sizeR = r-m;
    vector<int> arrL, arrR;

    for(int i = 0 ; i<sizeL ; i++){
        arrL.push_back(arr[l+i]);
    }
    for(int j = 0 ; j<sizeR ; j++){
        arrR.push_back(arr[m+1+j]);
    }

    int lp = 0 ,rp = 0;
    int curr = l;
    
    while(lp < sizeL && rp < sizeR){
        if(arrL[lp] <= arrR[rp]){
            arr[curr] = arrL[lp];
            lp++;
        }
        else{
            arr[curr] = arrR[rp];
            rp++;
        }
        curr++;
    }

    while(lp < sizeL){
        arr[curr] = arrL[lp];
        lp++;
        curr++;
    }
    while(rp < sizeR){
        arr[curr] = arrR[rp];
        rp++;
        curr++;
    }
}

void mergeSort(int l, int r){
    if(l >= r){
        return;
    }
    int m = l + (r-l)/2;

    mergeSort(l,m);
    mergeSort(m+1,r);

    merge(l,m,r);
}

void print(){
    for(int i = 0 ; i<n ; i++){
        if(i == n-1){
            cout << arr[i] << "\n";
        }
        else{
            cout << arr[i] << " ";
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    do{
        cin >> n;
        if(n == 0){
            continue;
        }
        for(int i = 0 ; i<n ; i++){
            int data;
            cin >> data;
            arr.push_back(data);
        }
        mergeSort(0,n-1);
        print();
        arr.clear();
    }while(n != 0);
    
    return 0;
}