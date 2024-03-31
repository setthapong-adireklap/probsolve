#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main(){

    int k, n;
    cin >> k >> n;

    int c, p, w;
    vector<vector<int>> carrental(k);
    for(int i = 0 ; i<k ; i++){
        cin >> c >> p >> w;
        carrental[i].push_back(c);
        carrental[i].push_back(p);
        carrental[i].push_back(w);
    }

    int a;
    vector<int> weight;
    for(int i = 0 ; i<n ; i++){
        cin >> a;
        weight.push_back(a);
    }

    int temp, count, current_w;
    bool status;
    int minCost = INT_MAX;
    for(int i = 0 ; i<k ; i++){
        count = 1;
        current_w = 0;
        status = true;
        for(int j = 0 ; j<n ; j++){
            current_w += weight[j];
            if(current_w > carrental[i][2]){
                count++;
                current_w = weight[j];
                if(current_w > carrental[i][2]){
                    status = false;
                    break;
                }
            }
        }
        if(status){
            temp = carrental[i][0] + count*carrental[i][1];
            minCost = (temp < minCost)? temp : minCost;
        }
    }

    cout << minCost << endl;

    return 0;
}