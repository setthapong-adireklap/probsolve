#include <bits/stdc++.h>

using namespace std;

vector<int> hippo;
int n,h,Ta,Td;

int totalTime(){
    int total = 0;
    int r = n-1;
    for(int i = 0 ; i<=r ; i++){
        while(hippo[i] + hippo[r] >= h && i != r){
            r--;
            total += Ta;
        }
        if(i != r){
            total += Td;
        }
        else{
            total += Ta;
        }
        r--;
    }
    if(n == 1){
        total += Ta;
    }
    total = min(total,n*Ta);
    
    return total;
}

int main(){
    
    int c;
    cin >> c;

    int tmp;
    for(int i = 0 ; i<c ; i++){
        cin >> n >> h >> Ta >> Td;
        for(int i = 0 ; i<n ; i++){
            cin >> tmp;
            hippo.push_back(tmp);
        }
        sort(hippo.begin(),hippo.end());
        cout << "Case " << i+1 << ": " << totalTime() << endl;
        hippo.clear();
    }

    return 0;
}