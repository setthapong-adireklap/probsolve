#include <iostream>
#include <set>

using namespace std;

int main(){

    int n, l;
    cin >> n >> l;
    
    int A,B,end_point;
    int fence = 0;
    set<pair<int,int>> timeInterval;
    for(int i = 0 ; i<n ; i++){
        cin >> A >> B;
        timeInterval.insert(make_pair(B,A));
    }

    for(auto i = timeInterval.begin() ; i != timeInterval.end() ; i++){
        if(i == timeInterval.begin()){
            end_point = i->second + l;
            fence++;
        }
        else if(i->first <= end_point){
            continue;
        }
        else if(i->first > end_point){
            end_point = i->second + l;
            fence++;
        }
    }
    cout << fence << endl;

    return 0;
}