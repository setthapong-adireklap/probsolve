#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main(){

    int n, mode, data;
    unordered_map<int,int> like;
    unordered_map<int,int> reverseCurr;
    unordered_map<int,int> curr;
    set<pair<int,int>> set_like;
    
    cin >> n;

    for(int i = 0 ; i<n ; i++){
        cin >> mode >> data;

        auto it = set_like.find(make_pair(like[data],curr[data]));
        if(it != set_like.end()){
            set_like.erase(it);
        }

        reverseCurr[i] = data;
        curr[data] = i;

        switch(mode){
        case 0:
            like[data] -= 1;
            break;
        
        case 1:
            like[data] += 1;
            break;
        }
        set_like.insert(make_pair(like[data],i));

        auto res = set_like.end();
        res--;
        
        cout << reverseCurr[res->second] << endl;
    }
    return 0;
}
