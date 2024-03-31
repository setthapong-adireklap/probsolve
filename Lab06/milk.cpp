#include <iostream>
#include <vector>

using namespace std;

vector<int> sParent;
vector<int> sRank;

int sfind(int u){
    if(sParent[u] == u){
        return u;
    }
    else{
        return sfind(sParent[u]);
    }
}

void unionMilk(int x, int y){
    x = sfind(x);
    y = sfind(y);
    if(x == y){
        return ;
    }
    if(sRank[x] > sRank[y]){
        sParent[y] = x; 
    }
    else if(sRank[x] < sRank[y]){
        sParent[x] = y; 
    }
    else{
        sParent[y] = x;
        sRank[x]++;
    }
}

int main(){

    int n,m;
    cin >> n >> m;

    for(int i = 0 ; i<n ;i++){
        sParent.push_back(i);
        sRank.push_back(0);
    }

    char a;
    int x,y;
    for(int i = 0 ; i<m ; i++){
        cin >> a >> x >> y;
        switch(a){
        case 'q':
            if(sfind(x) == sfind(y)){
                cout << "yes";
            }
            else{
                cout << "no";
            }
            cout << endl;
            break;
        case 'c':
            unionMilk(x,y);
            break;
        }
    }
    return 0;
}