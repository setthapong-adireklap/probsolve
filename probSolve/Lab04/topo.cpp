#include <iostream>
#include <vector>
#include <queue>
#define MAX_NODE 100000

using namespace std;

vector<int> adj[MAX_NODE];
bool visited[MAX_NODE];
bool inStack[MAX_NODE];
bool cycleDetected = false;

void DFS(int curr){
    visited[curr] = true;
    inStack[curr] = true;
    if(adj[curr].size() != 0){
        for(int i : adj[curr]){
            if(!cycleDetected){
                if(!visited[i] && !inStack[i]){
                    DFS(i);
                }
                else if(visited[i] && inStack[i]){
                    cycleDetected = true;
                }
            }
            else{
                break;
            }
        }
    }
    inStack[curr] = false;
}

void findCycle(int n){
    for(int i = 0 ; i<n ; i++){
        if(!visited[i]){
            DFS(i);
        }
        if(cycleDetected){
            break;
        }
    }
}

void findTopological(vector<int> &inDeg , int n){
    queue<int> Q;
    for(int i = 0 ; i<n ; i++){
        if(!inDeg[i]){
            Q.push(i);
        }
    }

    int u, v;
    while(!Q.empty()){
        u = Q.front();
        cout << u+1 << endl;
        Q.pop();
        for(int v : adj[u]){
            inDeg[v]--;
            if(!inDeg[v]){
                Q.push(v);
            }
        }
    }

}

void resetVisited(int n){
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }
}

int main(){

    int n,m;
    cin >> n >> m;

    vector<int> inDeg(n,0);

    int A,B;
    for(int i = 0 ; i<m ; i++){
        cin >> A >> B;
        A--; B--;
        adj[A].push_back(B);
        inDeg[B]++;
    }
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        inStack[i] = false;
    }

    findCycle(n);

    if(!cycleDetected){
        resetVisited(n);
        findTopological(inDeg,n);
    }
    else{
        cout << "no" << endl;
    }

    return 0;
}