#include <iostream>
#include <map>

using namespace std;

int main(){

    int n;
    cin >> n;

    map<int,int> like;
    int x, currMax;
    for(int i = 0 ; i<n ; i++){
        cin >> x;
        like[x]++;
        if(i == 0){
            currMax = x;    
        }
        if(like[x] >= like[currMax]){
            currMax = x;
        }
        cout << currMax << endl;
    }

    return 0;
}