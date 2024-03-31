#include <bits/stdc++.h>
#define MAX_SIZE 501

using namespace std;

int data_in[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];

void resetVal(int m ,int n){
    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            dp[i][j] = INT_MAX;
        }
    }
}

int findMin(int m, int n){
    
    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            int tmp = INT_MAX;
            for(int k = -1 ; k<2 ; k++){
                if(j-k < 0 || j-k >= n){
                    continue;
                }
                else if(i-1 < 0){
                    tmp = min(tmp,0);
                }
                else{
                    tmp = min(tmp,dp[i-1][j-k]);
                }
            }
            dp[i][j] = data_in[i][j] + tmp;
        }
    }

    int result = INT_MAX;
    for(int i = 0 ; i<n ; i++){
        result = min(result,dp[m-1][i]);
    }
    return result;
}

int main(){
    
    int t,m,n;
    cin >> t;
    for(int i = 0 ; i<t ; i++){
        cin >> m >> n;
        for(int j = 0 ; j<m ; j++){
            for(int k = 0 ; k<n ; k++){
                cin >> data_in[j][k];
                dp[j][k] = INT_MAX;
            }
        }
        cout << findMin(m,n) << endl;
        resetVal(m,n);
    }

    return 0;
}