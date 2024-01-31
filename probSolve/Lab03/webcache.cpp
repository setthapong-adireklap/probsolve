#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    
    queue<int> cache;
    unordered_map<int,bool> status;
    int x, missed = 0;
    for(int i = 0 ; i<m ; i++){
        cin >> x;
        if(!status[x]){
            missed++;
            status[x] = true;
            cache.push(x);
            if(cache.size()>n){
                status[cache.front()] = false;
                cache.pop();
            }
        }
    }
    cout << missed << endl;

    return 0;
}   