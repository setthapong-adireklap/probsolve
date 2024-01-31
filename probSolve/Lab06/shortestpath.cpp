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

void dijsktra(int s){
    set<pair<int,int>> Qs;
    D[s] = 0;
    Qs.insert(make_pair(0,s));
    
    int u, v;
    while(!Qs.empty()){
        u = Qs.begin()->second;
        Qs.erase(Qs.begin());
        if(visited[u]){
            continue;
        }
        visited[u] = true;

        for(int i = 0 ; i<deg[u] ; i++){
            v = adj[u][i];
            if(D[v] > D[u] + weight[u][i]){
                D[v] = D[u] + weight[u][i];
                Qs.insert(make_pair(D[v],v));
            }
        }
    }
    
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
    dijsktra(0);
    cout << D[n-1] << endl;

    return 0;
}