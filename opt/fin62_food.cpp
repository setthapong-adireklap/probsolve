#include <bits/stdc++.h>

using namespace std;

int food[5000];
int result[5000];

int main(){

    int n,k;
    cin >> n >> k;

    for(int i = 0 ; i<n ; i++){
        cin >> food[i];
    }

    int count = 0;
    for(int i = 0 ; i<n ; i++){
        count += food[i];
        if(count >= k){
            if(i == n-1 && count == k){
                result[i] = result[i-1];
                break;
            }
            count = food[i];
            result[i] = (food[i] > food[i-1] && count == k)? food[i-1]:food[i];
            if(i-2 >= 0){
                result[i] += food[i-2];
            }
        }
        else if(i != 0){
            result[i] = result[i-1];
        }
        else{
            result[i] = 0;
        }
    }
    cout << result[n-1] << endl;

    return 0;
}