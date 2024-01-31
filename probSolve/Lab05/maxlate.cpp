#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortPair(const pair<int, int> &a, const pair<int, int> &b){
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main(){

    int n;
    cin >> n;

    int A,B;
    vector<pair<int,int>> jobTime; 
    for(int i = 0 ; i<n ; i++){
        cin >> A >> B;
        jobTime.push_back(make_pair(A+10,B));
    }

    sort(jobTime.begin(),jobTime.end(),sortPair);

    int day = 0, maximum = 0;
    int temp;
    for(int i = 0 ; i<n ; i++){
        day += jobTime[i].second;
        if(jobTime[i].first - day < 0){
            temp = 1000*(day-jobTime[i].first);
            maximum = max(maximum,temp);
        }

    }
    cout << maximum << endl;

    return 0;
}