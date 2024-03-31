#include <bits/stdc++.h>

using namespace std;

int data_in[10010];
long long total = 0;

int main(){

    int n;
    cin >> n;

    for(int i = 0 ; i <n ; i++){
        cin >> data_in[i];
    }
    
    unordered_map<int,int> left;
    unordered_map<int,int> right;
    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            if(data_in[i] > data_in[j]){
                left[data_in[j]]++;
            }
            else{
                right[data_in[i]]++;
            }
        }
    }
    for(int i = 0 ; i<n ; i++){
        total += right[data_in[i]]*left[data_in[i]];
    }
    printf("%lld\n", total);

    return 0;
}