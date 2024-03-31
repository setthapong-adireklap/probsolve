#include <iostream>
#include <vector>
#include <queue>
#define MAX_NODE 1010

using namespace std;

vector<int> adj[MAX_NODE];
vector<int> color;
vector<int> deg;
vector<bool> visited;
vector<pair<int,int>> nodeEdges; 

void initAll(int n){
    for(int i = 0 ; i<n ; i++){
        deg.push_back(0);
        visited.push_back(false);
        color.push_back(-1);
    }
}

void resetAll(int n){
    for(int i = 0 ; i<n ; i++){
        visited[i] = false;
        color[i] = -1;
    }
}

void resetQ(queue<int> Q){
    while(!Q.empty()){
        Q.pop();
    }
}

bool isBipartite;

void findBipartite(pair<int,int> ignoreEdge, int start){
    queue<int> Q;
    Q.push(start);
    color[start] = 0;
    visited[start] = true;

    int u, v;
    int A = ignoreEdge.first, B = ignoreEdge.second ;
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        for(int i = 0 ; i<deg[u] ; i++){
            v = adj[u][i];
            if((v == A && u == B) || (u == A && v == B)){
                continue;
            }

            if(!visited[v]){
                Q.push(v);
                visited[v] = true;
                color[v] = (!color[u])? 1 : 0;
            }
            else if(visited[v] && color[u] == color[v]){
                isBipartite = false;
                resetQ(Q);
                break;
            }
        }
    }
    
}

int main(){

    int n,m;
    cin >> n >> m;

    initAll(n);

    int A,B;
    for(int i = 0 ; i<m ; i++){
        cin >> A >> B;
        A--; B--;
        adj[A].push_back(B);
        adj[B].push_back(A);
        deg[A]++; deg[B]++;
        nodeEdges.push_back(make_pair(A,B));
    }

    for(int i = 0 ; i<m ; i++){
        isBipartite = true;
        for(int j = 0 ; j<n ; j++){
            if(!visited[j]){
                findBipartite(nodeEdges[i],j);
                if(!isBipartite){
                    break;
                }
            }
        }
        if(isBipartite){
            cout << nodeEdges[i].first+1 << " " << nodeEdges[i].second+1 << endl;
            break;
        }
        resetAll(n);
    }

    return 0;
}