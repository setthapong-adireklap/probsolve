#include <iostream>
#include <vector>
#include <queue>
#define MAX_NODE 100

using namespace std;

vector<int> adj[MAX_NODE];
vector<int> inDeg(MAX_NODE,0);

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
        cout << u+1 << " ";
        Q.pop();
        for(int v : adj[u]){
            inDeg[v]--;
            if(!inDeg[v]){
                Q.push(v);
            }
        }
    }
    cout << endl;
}

void reset_adj(int n){
    for(int i = 0 ; i<n ; i++){
        adj[i].clear();
    }
}

int main(){

    int n = -1,m = -1;
    while(cin >> n >> m){
        if(!n && !m){
            break;
        }

        int A,B;
        for(int i = 0 ; i<m ; i++){
            cin >> A >> B;
            A--; B--;
            adj[A].push_back(B);
            inDeg[B]++;
        }

        findTopological(inDeg,n);
        reset_adj(n);
    }

    return 0;
}