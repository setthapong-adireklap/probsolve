#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canThrough = false;
int directon[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int checkRange1[4][2] = {{2,0},{-1,0},{0,2},{0,-1}};
int checkRange2[4][2] = {{2,1},{-1,1},{1,2},{1,-1}};

bool outOfRange(int pos,int size){
    if(pos<0 || pos >=size){
        return true;
    }
    return false;
}

void traversal(vector<vector<char>> &maze, vector<vector<bool>> &visited, vector<pair<int,int>> &start){
    queue<pair<int,int>> Q;
    int n = maze.size();
    int m = maze[0].size();
    for(int i = 0 ; i<start.size() ; i++){
        Q.push(start[i]);
        visited[start[i].first][start[i].second] = true;
    }
    pair<int,int> pos;
    int A,B,C,D;
    int X,Y;
    while(!Q.empty()){
        pos = Q.front();
        Q.pop();
        if(pos.first == n-2){
            canThrough = true;
            break;
        }
        for(int i = 0 ; i<4 ; i++){
            A = pos.first + checkRange1[i][0]; C = pos.first + checkRange2[i][0];
            B = pos.second + checkRange1[i][1]; D = pos.second + checkRange2[i][1]; 
            if(!outOfRange(B,m) && !outOfRange(D,m) && !outOfRange(A,n) && !outOfRange(C,n) && maze[A][B] == '.' && maze[C][D] == '.'){
                Y = pos.first + directon[i][0];
                X = pos.second + directon[i][1];
                if(!visited[Y][X]){
                    Q.push(make_pair(Y,X));
                    visited[Y][X] = true;
                    maze[Y][X] = 'x';
                }
            }
        }
    }
    
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<char>> maze(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    char a;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
           cin >> a;
           maze[i][j] = a; 
        }
    }

    vector<pair<int,int>> start;
    for(int i = 0 ; i<m ; i++){
        if(maze[0][i] == '.' && maze[1][i] == '.'){
            if(!outOfRange(i+1,m) && maze[0][i+1] == '.' && maze[1][i+1] == '.'){
                start.push_back(make_pair(0,i));
            }
        }
    }
    traversal(maze,visited,start);

    if(canThrough){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }

    return 0;
}