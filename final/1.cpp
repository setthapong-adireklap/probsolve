#include <bits/stdc++.h>
#define MAX_SIZE 500010
using namespace std;

int data_in[MAX_SIZE][3];
long long dp[MAX_SIZE][4];
long long total = 0;

int main(){

    int n;
    cin >> n;

    for(int i = 0 ; i <n ; i++){
        cin >> data_in[i][0] >> data_in[i][1] >> data_in[i][2];
        dp[i][0] = 0;
        dp[i][1] = data_in[i][0];
        dp[i][2] = data_in[i][1];
        dp[i][3] = data_in[i][2];
    }

    long long tmp;
    for(int i = 1 ; i<n ; i++){
        for(int j = 0 ; j<4 ; j++){
            tmp = max(dp[i-1][0],dp[i-1][1]);
            if(j == 0){
                tmp = max(tmp,dp[i-1][2]);
            }
            if(i-4 > 0){
                tmp = max(tmp,dp[i-4][3]);
            }
            if(i-2 > 0){
                tmp = max(tmp,dp[i-2][2]);
            }
            dp[i][j] += tmp;
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
    }
    
    for(int i = 0 ; i<4 ; i++){
        total = max(total,dp[n-1][i]);
    }
    cout << total << endl;

    return 0;
}