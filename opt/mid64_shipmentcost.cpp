#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#define MAX_NODE 100010

using namespace std;

vector<int> adj[MAX_NODE];
vector<bool> visited;
vector<int> layer;
vector<int> store;

void bfs(vector<int> &curr){
    queue<int> Q;
    for(auto i = curr.begin() ; i !=curr.end() ; i++){
        Q.push(*i);
        visited[*i] = true;
        layer[*i] = 0;
    }
    int u, v;
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        for(auto i = adj[u].begin() ; i != adj[u].end() ; i++){
            v = *i;
            if(!visited[v]){
                Q.push(v);
                visited[v] = true;
                layer[v] = layer[u] + 1;
            }
        }
    }
    
}

int main(){

    int n,m,s,t;
    cin >> n >> m >> s >> t;

    for(int i = 0 ; i<n ; i++){
        visited.push_back(false);
        layer.push_back(-1);
    }
    int A, B;
    for(int i = 0 ; i<m ; i++){
        cin >> A >> B;
        A--; B--;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    int a;
    for(int i = 0 ; i<s ; i++){
        cin >> a;
        a--;
        store.push_back(a);
    }
    bfs(store);
    for(int i = 0 ; i<t ; i++){
        cin >> a;
        a--;
        cout << layer[a] << endl;
    }

    return 0;
}