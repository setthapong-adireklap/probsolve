#include <bits/stdc++.h>

using namespace std;

int minVal[400][400];

bool isOutOfRange(int x, int n){
    if(x < 0 || x >= n){
        return true;
    }
    return false;
}

int findMin(string s1, string s2){
    if(s1.size() < s2.size()){ // base on max length 
        string tmp1 = s1;
        s1 = s2;
        s2 = tmp1;
    } // now s1 >= s2 
    int n = s1.size(), m = s2.size();
    
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            //from top
            if(!isOutOfRange(i-1,n)){
                minVal[i][j] = minVal[i-1][j] + 1;
            }
            else{
                minVal[i][j] = j + 1;
            }

            //from left
            if(!isOutOfRange(j-1,n)){
                minVal[i][j] = min(minVal[i][j],minVal[i][j-1] + 1);
            }
            else{
                minVal[i][j] = i + 1;
            }

            //from top left
            int isEq = (s1[i] == s2[j])? 0:1;
            int tmp2;
            if(isOutOfRange(i-1,n) && isOutOfRange(j-1,m)){
                tmp2 = 0;
            }
            else if(isOutOfRange(i-1,n)){
                tmp2 = j;
            }
            else if(isOutOfRange(j-1,m)){
                tmp2 = i;
            }
            else{
                tmp2 = minVal[i-1][j-1];
            }
            minVal[i][j] = min(minVal[i][j],tmp2+isEq);
        }
    }

    return minVal[n-1][m-1];
}

int main(){

    string s1,s2;
    cin >> s1 >> s2;

    cout << findMin(s1,s2) << endl;

    return 0;
}