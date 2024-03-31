#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define MAX_NODE 1000

using namespace std;

set<int> adj[MAX_NODE];
vector<bool> visited(MAX_NODE,false);
vector<int> layer(MAX_NODE,-1);

int direction[2][2] = {{-1,0},{0,-1}};

bool outOfRange(int curr, int size){
    if(curr < 0 || curr >= size){
        return true;
    }
    return false;
}

void bfs(int s){
    queue<int> Q;
    Q.push(s);
    visited[s] = true;
    layer[s] = 0;

    int u,v;
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        for(auto it = adj[u].begin() ; it != adj[u].end() ; it++){
            v = *it;
            if(!visited[v]){
                visited[v] = true;
                layer[v] = layer[u] + 1 ;
                Q.push(v);
            }
        }
    }
}

int main(){

    int R,C,A,B,X,Y;
    cin >> R >> C >> A >> B >> X >> Y;
    A--; B--; X--; Y--;

    int a,tmp;
    vector<vector<int>> countries(R,vector<int>(C));
    for(int i = 0 ; i<R ; i++){
        for(int j = 0 ; j<C ; j++){
            cin >> a;
            a--;
            countries[i][j] = a;
            for(int k = 0 ; k<2 ; k++){
                if(!outOfRange(i+direction[k][0],R) && !outOfRange(j+direction[k][1],C)){
                    tmp = countries[i+direction[k][0]][j+direction[k][1]];
                    if(a != tmp){
                        adj[a].insert(tmp);
                        adj[tmp].insert(a);
                    }
                }
            }
        }
    }
    int s = countries[A][B], e = countries[X][Y];
    bfs(s);
    cout << layer[e] << endl;

    return 0;
}