#include <iostream>
#include <vector>

using namespace std;

bool forest = false, hElement = false;

bool outOfRange(int pos,int size){
    if(pos<0 || pos >=size){
        return true;
    }
    return false;
}

int DFS(vector<vector<char>> &mapArea, vector<vector<bool>> &mapVisited,pair<int,int> pos){
    
    int walk = 0;
    mapVisited[pos.first][pos.second] = true;
    if(mapArea[pos.first][pos.second] == '#'){
        return walk;
    }
    vector<vector<int>> directon{{1,0},{-1,0},{0,1},{0,-1}};
    if(mapArea[pos.first][pos.second] == '*'){
        forest = true;
    }
    else if(mapArea[pos.first][pos.second] == '$'){
        hElement = true;
    }

    int row, col;

    for(int i = 0 ; i<4 ; i++){
        row = pos.first+directon[i][0];
        col = pos.second+directon[i][1];
        if(!outOfRange(row,mapArea.size()) && !outOfRange(col,mapArea[0].size())){
            if(!mapVisited[row][col]){
                walk += DFS(mapArea,mapVisited,make_pair(row,col));
            }
        }
    }
    return walk+1;
}

void countArea(vector<vector<char>> &mapArea, vector<vector<bool>> &mapVisited){
    
    int mediumArea = 0, highArea = 0;
    int temp;

    for(int i = 0 ; i<mapArea.size() ; i++){
        for(int j = 0 ; j<mapArea[i].size() ; j++){
            if(!mapVisited[i][j]){
                temp = DFS(mapArea,mapVisited,make_pair(i,j));
                if(forest && hElement){
                    highArea += temp;
                }
                else if(forest || hElement){
                    mediumArea += temp;
                }
                forest = false; hElement = false;
            }
        }
    }

    cout << highArea << " " << mediumArea << endl;
}

int main(){

    int n,m;
    cin >> n >> m;
    vector<vector<char>> mapArea(n, vector<char>(m));
    vector<vector<bool>> mapVisited(n, vector<bool>(m, false));

    char a;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            cin >> a;
            mapArea[i][j] = a;
        }
    }
    countArea(mapArea,mapVisited);

    return 0;
}