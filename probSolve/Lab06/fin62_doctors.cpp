#include <bits/stdc++.h>
#define MAX_NODE 100010
#define INFINITE 1000000010

using namespace std;

int n,m,l;

vector<int> adj[MAX_NODE];
vector<int> weight[MAX_NODE];
int deg[MAX_NODE];
int peopleAmount[MAX_NODE];
int D[MAX_NODE];
bool visited[MAX_NODE];

void dijkstra(int s){
    set<pair<int,int>> Qs;
    D[s] = 0;
    Qs.insert(make_pair(0,s));

    int u,v;
    while(!Qs.empty()){
        u = Qs.begin()->second;
        Qs.erase(Qs.begin());
        if(visited[u]){
            continue;
        }
        visited[u] = true;
        for(int i = 0 ; i<deg[u] ; i++){
            v = adj[u][i];
            if(D[v] > D[u] + weight[u][i]){
                D[v] = D[u] + weight[u][i];
                Qs.insert(make_pair(D[v],v));
            }
        }
    }
}

int totalPrice(){
    int total = 0;
    for(int i = 0 ; i<n ; i++){
        if(peopleAmount[i] < l){
            total += peopleAmount[i]*D[i];
        }
        else{
            total += l*D[i];
        }
    }
    return total;
}

int main(){

    cin >> n >> m >> l;

    int r;
    for(int i = 0 ; i<n ; i++){
        cin >> r;
        peopleAmount[i] = r;
        D[i] = INFINITE;
        visited[i] = false;
    }

    int a,b,c;
    for(int i = 0 ; i<m ; i++){
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        weight[a].push_back(c);
        weight[b].push_back(c);
        deg[a]++; deg[b]++;

    }
    dijkstra(0);
    cout << totalPrice() << endl;

    return 0;
}