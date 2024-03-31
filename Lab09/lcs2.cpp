#include <bits/stdc++.h>

using namespace std;

int xe,ye;
string s1, s2;
vector<vector<char>> direction;

bool isOutOfRange(int x, int n){
    if(x < 0 || x >= n){
        return true;
    }
    return false;
}

void print(int x, int y){
    int d = direction[y][x];
    switch(d){
    case 'I':
        if(!isOutOfRange(x-1,s2.size()) && !isOutOfRange(y-1,s1.size())){
            print(x-1,y-1);
        }
        cout << s1[y];
        break;
    case 'L':
        if(!isOutOfRange(x-1,s2.size())){
            print(x-1,y);
        }
        break;
    case 'T':
        if(!isOutOfRange(y-1,s1.size())){
            print(x,y-1);
        }
        break;
    }
}

int countLCS(){
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
                direction[i][j] = 'I';
            }
            if(!isOutOfRange(i-1,sizeS1) && maxLength[i][j] < maxLength[i-1][j]){
                maxLength[i][j] = maxLength[i-1][j];
                direction[i][j] = 'T';
            }
            if(!isOutOfRange(j-1,sizeS2) && maxLength[i][j] < maxLength[i][j-1]){
                maxLength[i][j] = maxLength[i][j-1];
                direction[i][j] = 'L';
            }
        }
    }

    int res = 0;
    for(int i = 0 ; i<sizeS2 ; i++){
        if(maxLength[sizeS1-1][i] > res){
            res = maxLength[sizeS1-1][i];
            xe = i;
        }
    }
    ye = sizeS1-1;
    return res;
}

int main(){

    cin >> s1 >> s2;

    for(int i = 0 ; i<s1.size() ;i++){
        direction.push_back({});
        for(int j = 0 ; j<s2.size() ; j++){
            direction[i].push_back('x');
        }
    }

    cout << countLCS() << endl;
    print(xe,ye);
    cout << endl;

    return 0;
}