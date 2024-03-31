#include <iostream>
#include <vector>
#include <list>

using namespace std;

void BFS(vector<int> adj[], vector<int> &deg, vector<int> &layer, vector<bool> &visited,int start,int target){
    
    list<int> Q;
    Q.push_back(start);
    visited[start] = true;
    layer[start] = 0;

    int u, v;
    while(!Q.empty()){
        u = Q.front();
        Q.pop_front();
        for(int i = 0 ; i<deg[u] ; i++){
            v = adj[u][i];
            if(!visited[v]){
                layer[v] = layer[u]+1;
                Q.push_back(v);
                visited[v] = true;
            }
        }
    }

}

int main(){

    int n,r;
    cin >> n >> r;
    
    vector<int> adj[n+2];
    vector<int> layer(n+2,-1);
    vector<int> deg(n+2,0);
    vector<bool> visited(n+2,false);
    vector<pair<int,int>> pos;

    pos.push_back(make_pair(0,0));
    int x, y;
    for(int i = 0 ; i < n ; i++){
        cin >> x >> y;
        pos.push_back(make_pair(x,y));
    }
    pos.push_back(make_pair(100,100));

    int distanceX ,distanceY;
    for(int i = 0 ; i<pos.size()-1 ; i++){
        for(int j = i+1 ; j<pos.size() ; j++){
            distanceX = abs(pos[i].first - pos[j].first);
            distanceY = abs(pos[i].second - pos[j].second);
            if((r*r) >= ((distanceX*distanceX) + (distanceY*distanceY))){
                adj[i].push_back(j);
                adj[j].push_back(i);
                deg[i]++; deg[j]++;
            }
        }
    }

    BFS(adj,deg,layer,visited,0,n+1);
    
    cout << layer[n+1] << endl;

    return 0;
}