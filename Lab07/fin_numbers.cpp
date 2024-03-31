#include <bits/stdc++.h>

using namespace std;

int n;

int main(){

    int tmp;

    cin >> n;
    vector<int> cost;
    vector<int> maximumCost = {0,0,0,0};
    unordered_map<int,int> nessesaryStep;
    for(int i = 0 ; i<n ; i++){
        cin >> tmp;
        cost.push_back(tmp);
    }
    for(int i = 0 ; i<n ; i++){
        cin >> tmp;
        nessesaryStep[i] = tmp;
    }

    int tmp_max, tmp_cost;
    for(int i = 0 ; i<n ; i++){    
        tmp_max = INT_MIN;
        for(int j = 1 ; j<5 ; j++){
            tmp_cost = cost[i] + maximumCost[i-j+4];
            tmp_max = max(tmp_max,tmp_cost);
            if(nessesaryStep[i-j] == 1){
                break;
            }
        }
        maximumCost.push_back(tmp_max);
    }

    int maxCost = INT_MIN;
    for(int i = 1 ; i<5 ; i++){
        if(n-i+4 >= 0){
            maxCost = max(maxCost,maximumCost[n-i+4]);
            if(nessesaryStep[n-i] == 1){
                break;
            }
        }
    }

    cout << maxCost << endl;

    return 0;
}