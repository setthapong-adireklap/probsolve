#include <bits/stdc++.h>

using namespace std;

list<int> virus;
int n,m;

void print(){
    for(auto i = virus.begin() ; i != virus.end() ; i++){
        cout << *i << endl;
    }
}

int main(){

    cin >> n >> m;
    int data;
    for(int i = 0 ; i<n ;i++){
        cin >> data;
        virus.push_back(data);
    }

    int op;
    auto it = virus.begin();
    for(int i = 0 ; i<m ; i++){
        cin >> op;
        switch(op){
        case 1:
            it = virus.begin();
            break;
        case 2:
            it++;
            if(it == virus.end()){
                it = it = virus.begin();
            }
            break;
        case 3:
            cin >> data;
            virus.insert(it,data);
            break;
        case 4:
            cin >> data;
            it++;
            virus.insert(it,data);
            it--;
            it--;
            break;
        }
    }
    print();

    return 0;
}