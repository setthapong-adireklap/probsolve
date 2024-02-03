#include <bits/stdc++.h>

using namespace std;

int n,q;
set<int> setPosible;
vector<int> qSum;

bool isPosible(int ques){
    auto it = setPosible.lower_bound(ques);
    if(it == setPosible.end()){
        return false;
    }
    if(*it == ques){
        return true;
    }
    return false;
}

void findAllPosible(){
    for(int i = 1 ; i<n ; i++){
        for(int j = 0; j<n-i ; j++){
            if(j == 0){
                setPosible.insert(qSum[j+i]);
            }
            else{
                setPosible.insert(qSum[j+i]-qSum[j-1]);
            }
        }
    }
}

int main(){

    cin >> n >> q;

    int data;
    for(int i = 0 ; i<n ; i++){
        cin >> data;
        setPosible.insert(data);
        if(i==0){
            qSum.push_back(data);
        }
        else{
            qSum.push_back(qSum[i-1]+data);
        }
    }
    findAllPosible();

    int ques;
    for(int i = 0 ; i<q ; i++){
        cin >> ques;
        if(isPosible(ques)){
            cout << "Y";
        }
        else{
            cout << "N";
        }
    }
    cout << endl;


    return 0;
}