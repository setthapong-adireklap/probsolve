#include <bits/stdc++.h>
#define MAX_SIZE 210

using namespace std;

int data_in[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE][MAX_SIZE];

int main(){

    int n,m,k;
    cin >> n >> m >> k;

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            cin >> data_in[i][j];
            dp[0][i][j] = data_in[i][j];
        }
    }
    for(int i = 1 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            dp[0][i][j] += dp[0][i-1][j];
        }
    }
    
    int tmp;
    for(int i = 0 ; i<k ; i++){
        for(int j = 0 ; j<n ; j++){
            for(int l = 0 ; l<m ; l++){
                tmp = 0;
                for(int x = -1 ; x<2 ; x++){    
                   if(l-x < 0 || l-x >= m){
                        continue;
                   }
                   else if(j-1 < 0){
                        tmp = max(tmp,0);
                   }
                   else{
                        tmp = max(tmp, dp[i][j-1][l-x]);
                   }
                }
                dp[i+1][j][l] = data_in[j][l] + tmp;
                if(j-1 >= 0){
                    dp[i+1][j][l] = max(dp[i+1][j][l],dp[i+1][j-1][l] + data_in[j][l]);
                }
            }
        }
    }
    
    int result = 0;
    for(int i = 0 ; i<n ; i++){
        result = max(result,dp[k][n-1][i]);
    }
    cout << result << endl;

    return 0;
}