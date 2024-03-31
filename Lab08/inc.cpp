#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> parent;
vector<int> arr;

void print(int p, int s){
    if(p != -1){
        print(parent[p],0);
        if(s == 0){
            cout << arr[p] << " ";
        }
        else{
            cout << arr[p] << endl;
        }
    }
}

int main(){

    int n;
    cin >> n;

    int tmp, endMax;
    int maxLIS = 1;
    vector<int> L;

    for(int i = 0 ; i<n ; i++){
        cin >> tmp;
        arr.push_back(tmp);
        parent.push_back(-1);
    }

    int max_tmp;
    for(int i = 0 ; i<n ; i++){
        max_tmp = 1;
        for(int j = 0 ; j<L.size() ; j++){
            if(arr[i] > arr[j]){
                if(L[j]+1 > max_tmp){
                    max_tmp = L[j]+1;
                    parent[i] = j;     
                }   
            }
        }
        L.push_back(max_tmp);
        maxLIS = max(maxLIS,max_tmp);
    }
    for(int i = n-1 ; i>=0 ; i--){
        if(L[i] == maxLIS){
            endMax = i;
            break;
        }
    }
    cout << maxLIS << endl;
    print(endMax,1);

    return 0;
}