#include <bits/stdc++.h>
#define MAX_NODE 220
#define INF 1500000

using namespace std;

vector<int> adj[MAX_NODE];
vector<int> weight[MAX_NODE];
vector<int> deg;
vector<int> D;
vector<bool> visited;
int mstLength = -1;
bool connect = false;

void prim(int s){
    set<pair<int,int>> Q;
    D[s] = 0;
    Q.insert(make_pair(0,s));
    
    int u,v,du;
    while(!Q.empty()){
        u = Q.begin()->second;
        du = Q.begin()->first;
        Q.erase(Q.begin());
        if(visited[u]){
            continue;
        }
        mstLength += du;
        visited[u] = true;

        for(int i = 0 ; i<deg[u] ; i++){
            v = adj[u][i];
            if(D[v] > weight[u][i]){
                D[v] = weight[u][i];
                Q.insert(make_pair(D[v],v));
            }
        }
    }
}

void revisit(int n){
    for(int i = 0 ; i<n ; i++){
        visited[i] = false;
        D[i] = INF;
    }
}

void isSpanning(int s, int n){

    queue<int> Q;
    Q.push(s);
    visited[s] = true;
    int total = n;
    total--;

    int u,v;
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        for(int i = 0 ; i<deg[u]; i++){
            v = adj[u][i];
            if(!visited[v]){
                visited[v] = true;
                Q.push(v);
                total--;
            }
        }
    }
    if(total == 0){
        connect = true;
    }    
}

int main(){

    int n,m;
    cin >> n >> m;
    for(int i = 0 ; i<n ; i++){
        visited.push_back(false);
        deg.push_back(0);
        D.push_back(INF);
    }

    int a,b,w;
    int totalNode = n;

    for(int i = 0 ; i<m ; i++){
        cin >> a >> b >> w;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++; deg[b]++;
        weight[a].push_back(w);
        weight[b].push_back(w);

        if(!connect){
            isSpanning(a,n);
            revisit(n);
        }
        if(connect){
            revisit(n);
            mstLength = 0;
            prim(0);
        }
        cout << mstLength << endl;
    }

    return 0;
}