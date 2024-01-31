#include <iostream>
#include <vector>
#include <queue>
#define MAX_N 500

using namespace std;

int n, shortestPath = 999999, counter = 0;

vector<vector<char>> maze(MAX_N,vector<char>(MAX_N));
vector<vector<bool>> visited(MAX_N,vector<bool>(MAX_N));
vector<vector<int>> layer(MAX_N,vector<int>(MAX_N));

vector<vector<int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
vector<vector<int>> jump = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

queue<pair<int,int>> Q2;

bool outOfRange(int curr){
    if(curr < 0 || curr >= n){
        return true;
    }
    return false;
}

void bfs1(int y, int x){
    queue<pair<int,int>> Q;
    Q.push(make_pair(y,x));
    layer[y][x] = 0;
    visited[y][x] = true;

    int a,b, uy, ux;
    while(!Q.empty()){
        uy = Q.front().first;
        ux = Q.front().second;
        Q.pop();
        for(int i = 0 ; i<4 ; i++){
            a = uy+direction[i][0];
            b = ux+direction[i][1];
            if(!outOfRange(a) && !outOfRange(b) && !visited[a][b]){
                visited[a][b] = true;
                layer[a][b] = layer[uy][ux] + 1;
                Q.push(make_pair(a,b));
            }
        }

    }
}

void bfs2(){

}

int main(){

    cin >> n;

    char a;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            cin >> a;
            maze[i][j] = a;
            visited[i][j] = (a == '#')? true: false;
            layer[i][j] = -1;
        }
    }
    bfs1(0,0);
    bfs2();
    cout << layer[n-1][n-1] << endl;

    return 0;
}