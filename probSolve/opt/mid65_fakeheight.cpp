#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;

    long long height;
    vector<long long> studentHeight;
    for(int i = 0 ; i<n ; i++){
        cin >> height;
        studentHeight.push_back(height);
    }

    return 0;
}