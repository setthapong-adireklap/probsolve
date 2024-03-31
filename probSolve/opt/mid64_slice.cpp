#include <bits/stdc++.h>

using namespace std;

vector<int> height;
vector<pair<int,int>> res;
unordered_map<int,int> tmpStore;
unordered_map<int,int> heightRes;
int n;

void print(){
    cout << res.size() << endl;
    for(int i = 0 ; i<=n ; i++){
        cout << res[i].first  << " " << res[i].second << endl;
    }
}

void storeInHR(){
    for(auto it = heightRes.begin() ; it != heightRes.end() ; it++){
        res.push_back(make_pair(it->first,it->second));
    }
    sort(res.begin(),res.end());
}

void storeValue(){
    int prev = 0, max_prev = 0;
    int currH;
    for(int i = 0 ; i<=n ; i++){
        currH = height[i];
        for(int j = 1 ; j<=currH ; j++){
            tmpStore[j]++;
        }
        if(currH < prev){
            for(int j = currH+1 ; j<=max_prev ; j++){
                heightRes[tmpStore[j]]++;
                tmpStore[j] = 0;
            }
            max_prev = currH;
        }
        max_prev = max(currH,max_prev);
        prev = currH;
    }
    storeInHR();
}

int main(){

    cin >> n;
    
    int data;
    int mn = INT_MAX;
    for(int i = 0 ; i<n ; i++){
        cin >> data;
        height.push_back(data);
        mn = min(data,mn);
    }
    for(int i = 0 ; i<n ; i++){
        height[i] -= mn;
    }
    if(mn != 0){
        heightRes[n] = mn;
    } 
    height.push_back(0);

    storeValue();
    print();

    return 0;
}