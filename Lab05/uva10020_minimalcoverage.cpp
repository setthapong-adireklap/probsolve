#include <bits/stdc++.h>

using namespace std;

int n, m;
int startP,endP;
bool isCover;
vector<pair<int,int>> sortP;
vector<pair<int,int>> sortRes;
vector<pair<int,int>> result;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b){
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

void minimize(){
    int start = 0;
    int s = sortRes.size();
    int x,y;

    for(int i = 0 ; i<s-1 ; i++){
        x = sortRes[i].first;
        y = sortRes[i].second;
        if(sortRes[i+1].first > start){
            result.push_back(make_pair(x,y));
            start = y;
        }
    }
    result.push_back(make_pair(sortRes[s-1].first,sortRes[s-1].second));
}

void findPossible(){
    int x,y;
    int s = sortP.size();
    for(int i = 0 ; i<s ; i++){
        x = sortP[i].first;
        y = sortP[i].second;
        if(i == 0){
            startP = x;
            endP = y;
            sortRes.push_back(make_pair(x,y));
        }
        if(endP >= m || startP > 0){
            break;
        }
        if(y <= endP){
            continue;
        }
        else if(x <= endP && y > endP){
            endP = y;
            sortRes.push_back(make_pair(x,y));
        }

    }
    if(endP >= m && sortRes[0].first <=0 && sortRes[0].second >= 0){
        isCover = true;
    }
}

void print(){
    cout << result.size() << endl;
    for(auto i = result.begin() ; i != result.end() ; i++){
        cout << i->first << " " << i->second << endl;
    }
    cout << "\n";
}

int main(){

    string blank;
    cin >> n;

    int a,b;
    for(int i = 0 ; i<n ; i++){
        getline(cin, blank);
        cin >> m;
        do{
            cin >> a >> b;
            if((!a && !b) || b<0){
                continue;
            }
            sortP.push_back(make_pair(a,b));
            
        } while(a || b);
        isCover = false;
        sort(sortP.begin(),sortP.end(),sortbysec);
        findPossible();
        if(isCover){
            minimize();
        }
        print();
        sortP.clear();
        sortRes.clear();
        result.clear();
    }

    return 0;
}