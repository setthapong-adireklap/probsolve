#include <iostream>

using namespace std;

int main(){

    int n, x;
    cin >> n;

    int* angle = new int[n];

    for(int i = 0 ; i<n ; i++){
        cin >> x;
        angle[i] = x; 
    }

    int count = 0;
    for(int i = 0 ; i<n-1 ; i++){
        for(int j = i+1 ; j<n ; j++){
            if(angle[i] < angle[j]){
                count += 1;
            }
        }
    }

    cout << count << endl;

    return 0;
}