#include <bits/stdc++.h>

using namespace std;

int main(){

    string core_msg;
    string msg;
    cin >> core_msg >> msg;

    int p = 0;
    int count = 0;
    for(int i = 0 ; i<msg.size() ; i++){
        if(core_msg[p] == msg[i]){
            p = (p+1)%core_msg.size();
            if(p == 0){
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}