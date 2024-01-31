#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<int> boat;
    unordered_map<int,int> remain;
    
    int tmp;
    for(int i = 0 ; i<n ; i++){
        cin >> tmp;
        remain[tmp]++;
        if(remain[tmp] == 1){
            boat.push_back(tmp);
        }
    }
    sort(boat.begin(), boat.end());

    vector<int>::iterator it;
    int countMax;
    bool status = true;
    for(int i = 0 ; i<m ; i++){
        cin >> tmp;
        if(status){
            it = lower_bound(boat.begin(), boat.end(), tmp);
            if(it == boat.end()){
                status = false;
                countMax = i;
            }
            else{
                remain[*it]--;
                if(!remain[*it]){
                    boat.erase(it);
                }
            }
        }
    }
    cout << countMax << endl;

    return 0;
}