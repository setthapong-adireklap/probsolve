#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;


int main(){

    int n;
    cin >> n;

    int tmp, endMax;
    int maxLIS = 1;
    vector<int> L;

    for(int i = 0 ; i<n ; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }

    int max_tmp;
    for(int i = 0 ; i<n ; i++){
        max_tmp = 1;
        for(int j = 0 ; j<L.size() ; j++){
            if(arr[i] > arr[j]){
                if(L[j]+1 > max_tmp){
                    max_tmp = L[j]+1;
                }   
            }
        }
        L.push_back(max_tmp);
        maxLIS = max(maxLIS,max_tmp);
    }

    cout << maxLIS << endl;

    return 0;
}