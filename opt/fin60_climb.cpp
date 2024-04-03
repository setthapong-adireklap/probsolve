#include <bits/stdc++.h>
#define MAX_SIZE 35

using namespace std;

int n, m;
int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int cost[4] = {5, 0, 1, 1};

char maze[MAX_SIZE][MAX_SIZE];
int layer[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

void bfs() {
  layer[n - 1][0] = 0;
  visited[n - 1][0] = true;
  queue<pair<int, int>> Q;
  Q.push(make_pair(n - 1, 0));

  int xu, xv, yu, yv;
  while (!Q.empty()) {
    xu = Q.front().second;
    yu = Q.front().first;
    Q.pop();
    for (int i = 0; i < 4; i++) {
      xv = xu + direction[i][1];
      yv = yu + direction[i][0];
      if (xv < 0 || xv >= m || yv < 0 || yv >= n) {
        continue;
      }
      if (maze[yv][xv] == 'X' || visited[yv][xv]) {
        continue;
      }
      layer[yv][xv] = layer[yu][xu] + cost[i];
      visited[yv][xv] = true;
      Q.push(make_pair(yv, xv));
    }
  }
}

int main() {

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      layer[i][j] = -1;
      visited[i][j] = false;
      cin >> maze[i][j];
    }
  }
  bfs();
  cout << layer[0][m - 1] << endl;

  return 0;
}
