#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

    vector<int> data;
    set<int> res;
    int n, x;
    cin >> n;
    
    for(int i = 0 ; i<n ; i++){
        cin >> x;
        data.push_back(x);
    }

    int tempSum;
    for(int i = 0 ; i<n ; i++){
        tempSum = 0;
        for(int j = i ; j<n ; j++){
            tempSum += data[j];
            res.insert(tempSum);
        }
    }

    cout << res.size() << endl;

    return 0;
}