#include <iostream>
#include <vector>
#include <queue>

#define MAX_NODE 100010

using namespace std;

vector<int> adj[MAX_NODE];
vector<int> deg;
vector<int> color;
vector<bool> visited; 

bool isBipartite = true;

void bipartite(int curr){
    if(color[curr] == 3){
        return;
    }
    queue<int> Q;
    Q.push(curr);
    visited[curr] = true;
    color[curr] = 0;

    int u, v;
    while(!Q.empty() && isBipartite){
        u = Q.front();
        Q.pop();
        for(int i = 0 ; i<deg[u] ; i++){
            v = adj[u][i];
            if(color[v] != 3){
                if(!visited[v]){
                    Q.push(v);
                    color[v] = (color[u])? 0 : 1;
                    visited[v] = true;
                }
                else if(color[u] == color[v]){
                    isBipartite = false;
                    break;
                }
            }
            else{
                visited[v] = true;
            }
        }
    }
}

int main(){

    int n,m,k;
    cin >> n >> m >> k;

    for(int i = 0 ; i<n ; i++){
        deg.push_back(0);
        color.push_back(-1);
        visited.push_back(false);
    }

    int A,B;
    int countMax = 0;
    for(int i = 0 ; i<m ; i++){
        cin >> A >> B;
        A--; B--;
        adj[A].push_back(B);
        adj[B].push_back(A);
        deg[A]++; deg[B]++;
        if(deg[A] >= k){
            color[A] = 3;
        }
        if(deg[B] >= k){
            color[B] = 3;
        }
    }

    for(int i = 0 ; i<n ; i++){
        if(isBipartite && !visited[i]){
            bipartite(i);
        }
    }
    
    if(isBipartite){
        cout << "yes";
    }
    else{
        cout << "no";
    }
    cout << endl;

    return 0;
}