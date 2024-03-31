#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){

    int n, tmp;
    cin >> n;
    
    unordered_map<int, vector<int>> map;
    for(int i = 0 ; i<n; i++){
        cin >> tmp;
        tmp--;
        map[(n+tmp-i)%n].push_back(tmp);
    }

    int result = (map.begin()->second).size();
    for(auto it = map.begin() ; it != map.end() ; it++){
        tmp = it->second.size();
        if(result < tmp){
            result = tmp;
        }
    }
    cout << result << endl;

    return 0;
}