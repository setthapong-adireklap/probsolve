#include <iostream>
#include <set>

using namespace std;

int main(){

    int n;
    cin >> n;
    
    int A,B, end_point;
    int count_interval = 0;
    set<pair<int,int>> timeInterval;
    for(int i = 0 ; i<n ; i++){
        cin >> A >> B;
        timeInterval.insert(make_pair(B,A));
    }

    for(auto i = timeInterval.begin() ; i != timeInterval.end() ; i++){
        if(i == timeInterval.begin()){
            end_point = i->first;
            count_interval++;
        }
        else if(i->first != end_point && i->second >= end_point){
            end_point = i->first;
            count_interval++;
        }
    }
    cout << count_interval << endl;

    return 0;
}

/*
another version

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int n;
    int s, e;
    vector <pair <int, int>> v;

    cin >> n;
    pair <int, int> interval;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        interval.first = s;
        interval.second = e;
        v.push_back(interval);
    }

    sort(v.begin(), v.end(), sortbysec);
    s = v[0].first; e = v[0].second;
    int result = 1;
    for (int i = 1; i < n; i++) {
        if (e <= v[i].first) {
            e = v[i].second;
            result++;
        }
    }
    cout << result;
    return 0;
}
*/