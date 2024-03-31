#include <iostream>
#include <vector>
#include <queue>
#define MAX_NONDE 50020

using namespace std;

vector<pair<int,int>> adj[MAX_NONDE];
vector<bool> visited(MAX_NONDE,false);
vector<int> layer(MAX_NONDE,-1);

int s, t;
int result, tmp;

void resetVisited(){
    for(auto u = visited.begin() ; u != visited.end() ; u++){
        *u = false;
    }
}

void bfs(int curr,int color){
    queue<int> Q;
    Q.push(curr);
    layer[curr] = 0;
    visited[curr] = true;
    
    int u, v;
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        for(auto i = adj[u].begin() ; i != adj[u].end() ; i++){
            v = i->first;
            if(!visited[v] && (i->second == 0 || i->second == color)){
                Q.push(v);
                visited[v] = true;
                layer[v] = layer[u] + 1;
            }
        }
    }
}

int main(){

    int n,m;
    cin >> n >> m >> s >> t;
    s--; t--;

    int A,B,C;
    for(int i = 0 ; i<m ; i++){
        cin >> A >> B >> C;
        A--; B--;
        adj[A].push_back(make_pair(B,C));
        adj[B].push_back(make_pair(A,C));
    }
    bfs(s,1);
    tmp = layer[t];
    resetVisited();
    bfs(s,2);
    result = layer[t];

    if(result == -1 && tmp != -1){
        result = tmp;
    }
    else if(result != -1 && tmp != -1){
        result = (result < tmp)? result: tmp;
    }

    cout << result << endl;
    return 0;
}