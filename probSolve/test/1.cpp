#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, l;
vector<int> house;
vector<int> totalSum;

void setUp(){
    int tmp;
    for(int i = 1 ; i<n ; i++){
        tmp = house[i]-house[i-1];
        if(i==1){
            totalSum.push_back(0);
            totalSum.push_back(tmp);
        }
        else{
            totalSum.push_back(tmp + totalSum[i-1]);
        }
    }
}

int findMaxlength(){
    int result, tmp;
    int wire = k+l;
    for(int i = 0 ; i<n-wire ; i++){
        tmp = totalSum[wire+i]-totalSum[i];
        if(i == 0){
            result = tmp;
        }
        else{
            result = (tmp > result)? tmp : result;
        }
    }
    return result;
}

int main(){

    cin >> n >> k >> l;
    
    int tmp;
    for(int i = 0 ; i<n ; i++){
        cin >> tmp;
        house.push_back(tmp);
    }
    sort(house.begin(), house.end());

    setUp();
    
    int result = findMaxlength();
    cout << result << endl;

    return 0;
}