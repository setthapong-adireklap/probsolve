#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void resverse(vector<int> &smallJ, vector<int> &smallK){
    stack<int> S;
    for(auto i = smallJ.begin() ; i != smallJ.end() ; i++){
        S.push(*i);
    }
    while(!S.empty()){
        smallK.push_back(S.top());
        S.pop();
    }
}

int findPosition(vector<int> &smallK, int value){

    auto curr = lower_bound(smallK.begin(),smallK.end(),value);
    if(curr == smallK.end()){
        return 0;
    }
    else{
        int pos = curr - smallK.begin();
        return smallK.size() - pos;
    }

}

int main(){

    int n, q;
    cin >> n >> q;

    vector<int> smallJ;

    int tmp;
    for(int i = 0 ; i<n ; i++){
        cin >> tmp;
        if(i == 0){
            smallJ.push_back(tmp);
        }
        else{
            if(tmp <= smallJ[i-1]){
                smallJ.push_back(tmp);
            }
            else{
                smallJ.push_back(smallJ[i-1]);
            }
        }
    }

    vector<int> smallK;
    resverse(smallJ,smallK);

    int op, value;
    for(int i = 0 ; i<q ; i++){
        cin >> op >> value;
        if(op == 1){
            value--;
            cout << smallJ[value] << endl;
        }
        else if(op == 2){
            cout << findPosition(smallK,value) << endl;
        }
    }

    return 0;
}