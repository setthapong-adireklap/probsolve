#include <bits/stdc++.h>
#define MAX_NODE 100010

using namespace std;

vector<pair<int,int>> edges;
vector<pair<int,int>> sortWeight;

vector<int> sRank;
vector<int> sParent;
vector<bool> visited;

bool status = true;

int n,m;

void setUp(){
    for(int i = 0 ; i<n ; i++){
        sRank.push_back(0);
        sParent.push_back(i);
        visited.push_back(false);
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

    int a,b,c;
    for(int i = 0 ; i<m ; i++){
        cin >> a >> b >> c;
        a--; b--;
        edges.push_back(make_pair(a,b));
        sortWeight.push_back(make_pair(c,i));
    }
    sort(sortWeight.begin(), sortWeight.end());

    int e,u,v,w,pu,pv;
    long long total = 0;
    int count_edge = 0;
    for(int i = 0 ; i<m ; i++){
        e = sortWeight[i].second;
        u = edges[e].first;
        v = edges[e].second;
        w = sortWeight[i].first;

        pu = sFind(u);
        pv = sFind(v);
        if(status && pu == pv){
            total += w;
            status = false;
            count_edge++;
        }
        else if(pu != pv){
            total += w;
            sUnion(u,v);
            count_edge++;
        }
    }
    if(count_edge != n){
        total = -1;
    }
    cout << total << endl;

    return 0;
}