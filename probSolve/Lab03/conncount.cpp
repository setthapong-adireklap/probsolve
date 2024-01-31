#include <iostream>
#include <vector>
#include <list>

using namespace std;

void BFS(vector<int> adj[], vector<int> &deg, vector<bool> &visited,int start){
    
    list<int> Q;
    Q.push_back(start);
    visited[start] = true;

    int u, v;
    while(!Q.empty()){
        u = Q.front();
        Q.pop_front();
        for(int i = 0 ; i<deg[u] ; i++){
            v = adj[u][i];
            if(!visited[v]){
                Q.push_back(adj[u][i]);
                visited[v] = true;
            }
        }
    }

}

int main(){

    int n, m;
    cin >> n >> m ;

    vector<int> adj[n];
    vector<int> deg(n,0);
    vector<bool> visited(n,0);

    int A,B;
    for(int i = 0 ; i<m ; i++){
        cin >> A >> B; A--; B--;
        adj[A].push_back(B);
        adj[B].push_back(A);
        deg[A]++; deg[B]++;
    }
    
    int countConnected = 0;
    
    for(int i = 0 ; i<n ; i++){
        if(!visited[i]){
            BFS(adj,deg,visited,i);
            countConnected++;
        }
    }

    cout << countConnected << endl;

    return 0;
}