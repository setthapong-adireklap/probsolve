#include <iostream>

using namespace std;

int main(){

    int n, k, t;
    cin >> n >> k >> t;

    int count = 0, next = 0;

    while(true){
        if(t == 1){
            count += 1;
            break;
        }
        count += 1;
        next = (next+k)%n;
        if(next == 0){
            break;
        } 
        else if(next == t-1){
            count += 1;
            break;
        }
    }

    cout << count << endl;

    return 0;
}