#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m,a,b;
    cin >> n;

    unordered_map<int,int> day;
    int total = 0;
    for(int i = 0 ; i<n ; i++){
        cin >> m;
        for(int j = 0 ; j<m ; j++){
            cin >> a >> b;
            total += a;
            day[i+b] += a;
        }
        total -= day[i];
        cout << total << endl;
    }

    return 0;
}