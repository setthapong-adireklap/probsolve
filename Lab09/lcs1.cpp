#include <bits/stdc++.h>

using namespace std;

bool isOutOfRange(int x, int n){
    if(x < 0 || x >= n){
        return true;
    }
    return false;
}

int countLCS(string s1, string s2){
    int sizeS1 = s1.size(), sizeS2 = s2.size();
    vector<vector<int>> maxLength(sizeS1,vector<int>(sizeS2));

    for(int i = 0 ; i<sizeS1 ; i++){
        for(int j = 0 ; j<sizeS2 ; j++){
            maxLength[i][j] = 0;
            if(s1[i] == s2[j]){
                maxLength[i][j] = 1;
                if(!isOutOfRange(i-1,sizeS1) && !isOutOfRange(j-1,sizeS2)){
                    maxLength[i][j] += maxLength[i-1][j-1];
                }
            }
            if(!isOutOfRange(i-1,sizeS1) && maxLength[i][j] < maxLength[i-1][j]){
                maxLength[i][j] = maxLength[i-1][j];
            }
            if(!isOutOfRange(j-1,sizeS2) && maxLength[i][j] < maxLength[i][j-1]){
                maxLength[i][j] = maxLength[i][j-1];
            }
        }
    }

    int res = 0;
    for(int i = 0 ; i<sizeS2 ; i++){
        res = max(res,maxLength[sizeS1-1][i]);
    }
    return res;
}

int main(){

    string s1, s2;
    cin >> s1 >> s2;

    cout << countLCS(s1,s2) << endl;

    return 0;
}