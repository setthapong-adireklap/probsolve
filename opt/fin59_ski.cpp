#include <bits/stdc++.h>
#define MAX_SIZE 1010

using namespace std;

int n, k;
int maxScore = 0;

int height[MAX_SIZE];
int score[MAX_SIZE];
int dp[MAX_SIZE];

void findMaxScore(){
  for(int i = 0 ; i<n ; i++){
    dp[i] = score[i];
    for(int j = 0 ; j<i ; j++){
      if(height[j] < height[i] || height[j] - height[i] > k){
        continue;
      }
      dp[i] = max(dp[i], dp[j] + score[i]);
    }
    maxScore = max(maxScore, dp[i]);
  }
}

int main() {

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> height[i] >> score[i];
  }
  findMaxScore();
  cout << maxScore << endl;

  return 0;
}
