#include <bits/stdc++.h>
#define MAX_SIZE 31

using namespace std;

int data_in[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];

void findMin(int n, int m){
    int tmp;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            tmp = 0;
            for(int k = 0 ; k<=j ; k++){
                tmp += data_in[i][k];
            }
            dp[i][j] = tmp;
            tmp = 0;
            for(int k = j ; k<m ; k++){
                tmp += data_in[i][k];
            }
            dp[i][j] = min(dp[i][j],tmp);
            tmp = 0;
            for(int k = 0 ; k<=i ; k++){
                tmp += data_in[k][j];
            }
            dp[i][j] = min(dp[i][j],tmp);
            tmp = 0;
            for(int k = i ; k<n ; k++){
                tmp += data_in[k][j];
            }
            dp[i][j] = min(dp[i][j],tmp);
        }
    }
}

void print(int n, int m){
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    int n,m;
    cin >> n >> m;

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            cin >> data_in[i][j];
            if(i == 0 || i == n-1 || j == 0 || j == m-1){
                dp[i][j] = data_in[i][j];
            }
            else{
                dp[i][j] = INT_MAX;
            }
        }
    }
    findMin(n,m);
    print(n,m);

    return 0;
}