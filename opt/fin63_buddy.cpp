#include <bits/stdc++.h>
#define MAX_SIZE 100010

using namespace std;

int data_in[MAX_SIZE];
int sp[MAX_SIZE];
int srank[MAX_SIZE];

int sfind(int x){
    if(x != sp[x]){
        return sfind(sp[x]);
    }
    else{
        return x;
    }
}

void sUnion(int a, int b){
    int x = sfind(a);
    int y = sfind(b);
    if(srank[x] > srank[y]){
        sp[y] = x;
    }
    else if(srank[y] > srank[x]){
        sp[x] = y;
    }
    else{
        sp[y] = x;
        srank[x]++;
    }
}

int main(){

    int n;
    cin >> n;
    for(int i = 0 ; i<n ; i++){
        cin >> data_in[i];
        data_in[i]--;
        sp[i] = i;
        srank[i] = 0;
    }

    for(int i = 0 ; i<n ; i++){
        if(sfind(sp[i]) != sfind(data_in[i])){
            sUnion(i,data_in[i]);
        }
    }

    unordered_map<int,int> res;
    for(int i = 0 ; i<n ; i++){
        res[sfind(sp[data_in[i]])] = 1;
    }
    cout << res.size() << endl;

    return 0;
}