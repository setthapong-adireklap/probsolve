#include <iostream>
#include <map>

using namespace std;

int main(){

    map<int,int> mp;
    int n, in1, in2;
    cin >> n;

    for(int i = 0 ; i<n ; i++){
        cin >> in1 >> in2;
        mp[in1] = in2;
    }

    int out = 0;
    int check = mp.begin()->second;
    for(auto i = mp.begin() ; i!=mp.end() ; i++){   
        if(i->second >= check){
            check = i->second;
        }
        else{
            out++;
        }
    }

    cout << out << endl;

    return 0;
}