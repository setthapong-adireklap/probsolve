#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool found = false;

void BFS(vector<int> adj[], vector<int> &deg, vector<bool> &visited, vector<int> &graph_type, int start){
    
    list<int> Q;
    Q.push_back(start);
    visited[start] = true;
    graph_type[start] = 0;

    int u, v;
    while(!found){
        u = Q.front();
        Q.pop_front();
        for(int i = 0 ; i<deg[u] ; i++){
            v = adj[u][i];
            if(graph_type[v] == -1){
                graph_type[v] = (!graph_type[u])? 1: 0;
            }
            else if(graph_type[v] == graph_type[u]){
                found = true;
                break;
            }
            if(!visited[v]){
                Q.push_back(v);
                visited[v] = true;
            }
        }
        if(Q.empty()){
            break;
        }
    }
}

int main(){

    int k,n,m;
    cin >> k;
    for(int i = 0 ; i<k ; i++){
        
        cin >> n >> m ;

        vector<int> adj[n];
        vector<int> deg(n,0);
        vector<int> graph_type(n,-1);
        vector<bool> visited(n,0);
        found = false;

        int A,B;
        for(int i = 0 ; i<m ; i++){
            cin >> A >> B; A--; B--;
            adj[A].push_back(B);
            adj[B].push_back(A);
            deg[A]++; deg[B]++;
        }

        for(int i = 0 ; i<n ; i++){
            if(!visited[i]){
                BFS(adj,deg,visited,graph_type,i);
            }
        }

        if(!found){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }

        adj->clear();
        deg.clear();
        graph_type.clear();
        visited.clear();
    }

    return 0;
}