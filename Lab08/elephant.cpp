#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;
vector<int> maxCost = {0,0,0};

int main(){

    cin >> n;

    int tmp;

    for(int i = 0 ; i<n ; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }

    int max_tmp;
    for(int i = 3 ; i<n+1 ; i++){
        max_tmp = max(maxCost[i-3]+arr[i-1],maxCost[i-1]);
        maxCost.push_back(max_tmp);
    }

    cout << maxCost[n] << endl;

    return 0;
}