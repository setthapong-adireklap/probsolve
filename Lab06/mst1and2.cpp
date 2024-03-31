#include <iostream>
#include <vector>
#include <set>
#define MAX_NODE 100010
#define INFINITY 1000000000

using namespace std;

vector<int> adj[MAX_NODE];
vector<int> weight[MAX_NODE];
vector<int> deg;
vector<int> D;
vector<bool> visited;

int mst(int s){
    set<pair<int,int>> Qs;
    D[s] = 0;
    Qs.insert(make_pair(0,s));
    
    int totalWeight = 0;
    int u, v, du;
    while(!Qs.empty()){
        u = Qs.begin()->second;
        du = Qs.begin()->first;
        Qs.erase(Qs.begin());
        if(visited[u]){
            continue;
        }
        totalWeight += du;
        visited[u] = true;

        for(int i = 0 ; i<deg[u] ; i++){
            v = adj[u][i];
            if(D[v] > weight[u][i]){
                D[v] = weight[u][i];
                Qs.insert(make_pair(D[v],v));
            }
        }
    }
    return totalWeight;
}

int main(){

    int n,m;
    cin >> n >> m;
    
    for(int i = 0 ; i<n ; i++){
        deg.push_back(0);
        visited.push_back(false);
        D.push_back(INFINITY);
    }

    int A,B,w;
    for(int i = 0 ; i<m ; i++){
        cin >> A >> B >> w;
        A--; B--;
        adj[A].push_back(B);
        adj[B].push_back(A);
        weight[A].push_back(w);
        weight[B].push_back(w);
        deg[A]++; deg[B]++;
    }
    cout << mst(0) << endl;

    return 0;
}