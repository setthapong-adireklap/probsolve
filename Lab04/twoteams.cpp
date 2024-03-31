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
            if(!visited[v]){
                Q.push(v);
                color[v] = (color[u])? 0 : 1;
                visited[v] = true;
            }
            else{
                if(color[u] == color[v]){
                    isBipartite = false;
                    break;
                }
            }
        }
    }
}

void checkAndUpdate(int A, int B){
    if(!visited[A] && !visited[B]){
        visited[A] = true;
        visited[B] = true;
        color[A] = 0;
        color[B] = 1;
    }
    else if(!visited[A]){
        visited[A] = true;
        color[A] = (color[B])? 0 : 1;
    }
    else if(!visited[B]){
        visited[B] = true;
        color[B] = (color[A])? 0 : 1;
    }
}

void resetStatus(int curr){
    queue<int> Q;
    Q.push(curr);
    visited[curr] = false;
    color[curr] = -1;

    int u, v;
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        for(int i = 0 ; i<deg[u] ; i++){
            v = adj[u][i];
            if(visited[v]){
                Q.push(v);
                visited[v] = false;
                color[v] = -1;
            }
        }
    }
    
}

int main(){

    int n,m;
    cin >> n >> m;

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
        if(isBipartite){
            adj[A].push_back(B);
            adj[B].push_back(A);
            deg[A]++; deg[B]++;

            if(visited[A] && visited[B]){
                if(color[A] == color[B]){
                    resetStatus(A);
                    bipartite(A);
                }
            }
            else{
                checkAndUpdate(A,B);
            }
            countMax++;
        }
        if(isBipartite && i == m-1){
            countMax++;
        }
    }

    cout << countMax-1 << endl;

    return 0;
}