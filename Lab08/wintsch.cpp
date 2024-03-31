#include <bits/stdc++.h>

using namespace std;

int n;
int sizeSeq = 0;
vector<int> resultSeq;
vector<int> bestCost;
vector<vector<int>> point;

void print(int p, int s){
    if(p != -1){
        print(resultSeq[p],0);
        if(s == 0){
            cout << p+1 << " ";
        }
        else{
            cout << p+1 << endl;
        }
    }
}

void countLength(int p, int s){
    if(p != -1){
        countLength(resultSeq[p],0);
        sizeSeq++;
    }
}

int main(){

    int a,b,w;

    cin >> n;
    for(int i = 0 ; i<n ; i++){
        cin >> a >> b >> w;
        point.push_back({a,b,w});
        resultSeq.push_back(-1);
    }
    sort(point.begin(),point.end());

    int currCost, tmpMax;    
    for(int i = 0 ; i<n ; i++){
        a = point[i][0];
        currCost = point[i][2];
        tmpMax = 0;
        for(int j = 0 ; j<i ; j++){
            b = point[j][1];
            if(b > a){
                continue;
            }
            if(tmpMax < bestCost[j] + currCost){
                tmpMax = bestCost[j] + currCost;
                resultSeq[i] = j;
            }
        }
        tmpMax = max(tmpMax,currCost);
        bestCost.push_back(tmpMax);
    }

    int maxCost = INT_MIN, start;
    for(int i = n-1 ; i>=0 ; i--){
        if(maxCost < bestCost[i]){
            maxCost = bestCost[i];
            start = i;
        }        
    }
    countLength(start,1);

    cout << maxCost << endl;
    cout << sizeSeq << endl;
    print(start,1);

    return 0;
}