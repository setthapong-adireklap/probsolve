#include <bits/stdc++.h>

using namespace std;

vector<int> prime;

bool isPrime(int n){
    if(n == 1){
        return false;
    }
    else if(n == 2 || n == 3){
        return true;
    }
    for(int i = 2 ; i*i <= n ; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int countFriends(){
    if(prime.size() <= 1){
        return 0;
    }
    int total = 0;
    for(int i = 1 ; i<prime.size() ; i++){
        if(abs(prime[i-1]-prime[i]) == 2){
            total++;
        }
    }
    return total;
}

int main(){

    int l,r;
    cin >> l >> r;

    if(l%2 == 0){
        l++;
    }
    for(int i = l ; i<=r ; i += 2){
        if(isPrime(i)){
            prime.push_back(i);
        }
    }
    cout << countFriends() << endl;

    return 0;
}