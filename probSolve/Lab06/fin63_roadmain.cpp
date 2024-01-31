#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_NODE 100010

using namespace std;

vector<pair<int,int>> edges;
vector<pair<int,int>> sortWeight;

vector<int> sRank;
vector<int> sParent;

int n,m;

void setUp(){
    for(int i = 0 ; i<n ; i++){
        sRank.push_back(0);
        sParent.push_back(i);
    }
}

int sFind(int u){
    if(sParent[u] == u){
        return u;
    }
    else{
        return sFind(sParent[u]);
    }
}

void sUnion(int x, int y){
    x = sFind(x);
    y = sFind(y);
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

    cin >> n >> m;
    setUp();

    int a,b,c,d;
    int count = 0;
    for(int i = 0 ; i<m ; i++){
        cin >> a >> b >> c >> d;
        a--; b--;
        edges.push_back(make_pair(a,b));
        if(d == 1){
            sUnion(a,b);
        }
        else{
            sortWeight.push_back(make_pair(c,i));
            count++;
        }
    }
    sort(sortWeight.begin(), sortWeight.end());

    int e,u,v,w,pu,pv;
    int total = 0;
    for(int i = 0 ; i<count ; i++){
        e = sortWeight[i].second;
        u = edges[e].first;
        v = edges[e].second;
        w = sortWeight[i].first;

        pu = sFind(u);
        pv = sFind(v);
        if(pu != pv){
            total += w;
            sUnion(u,v);
        }
    }
    cout << total << endl;

    return 0;
}