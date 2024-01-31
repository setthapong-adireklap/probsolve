#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> directon{{1,0},{-1,0},{0,1},{0,-1}};
pair<int,int> target;

stack<bool> key;
bool currKey = true;
bool found;

bool outOfRange(int pos,int size){
    if(pos<0 || pos >=size){
        return true;
    }
    return false;
}

void traversal(vector<vector<char>> &maze, vector<vector<bool>> &mazeVisited, pair<int,int> &currPos){
    
    mazeVisited[currPos.first][currPos.second] = true;
    if(currPos.first == target.first && currPos.second == target.second){
        found = true;
    }
    int row ,col;
    if(currKey){
        key.push(true);
    }
    else{
        key.push(false);
    }
    pair<int,int> nextPos; 
    for(int i = 0; i<4 ; i++){
        row = currPos.first + directon[i][0];
        col = currPos.second + directon[i][1];
        currKey = key.top();
        if(!outOfRange(row,maze.size()) && !outOfRange(col,maze.size())){
            if(maze[row][col] == '#'){
                mazeVisited[row][col] = true;
            }
            else if(maze[row][col] == 'O' && !currKey){
                mazeVisited[row][col] = true;
            }
            if(!mazeVisited[row][col]){
                nextPos = make_pair(row,col);
                if(maze[row][col] == 'O'){
                    currKey = false;
                }
                traversal(maze,mazeVisited,nextPos);
            }
        }
        if(found){
            break;
        }
    }
    key.pop();
}

void resetVisited(vector<vector<bool>> &mazeVisited){
    int n = mazeVisited.size();
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            mazeVisited[i][j] = false;
        }
    }
}

int main(){

    int n,q;
    cin >> n >> q;
    vector<vector<char>> maze(n, vector<char>(n));
    vector<vector<bool>> mazeVisited(n, vector<bool>(n, false));

    char a;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            cin >> a;
            maze[i][j] = a;
        }
    }

    int R,C,A,B;
    pair<int,int> start;
    for(int i = 0 ; i<q ; i++){
        found = false;
        currKey = true;
        cin >> R >> C >> A >> B;
        R--; C--; A--; B--;
        target = make_pair(A,B);
        start = make_pair(R,C);
        traversal(maze,mazeVisited,start);
        if(found){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
        resetVisited(mazeVisited);
    }   

    return 0;
}