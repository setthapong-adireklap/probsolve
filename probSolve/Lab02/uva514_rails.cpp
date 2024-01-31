#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void clearStack(stack<int> &s){
    while(!s.empty()){
        s.pop();
    }
}

void clearQueue(queue<int> &q){
    while(!q.empty()){
        q.pop();
    }
}

void rails(stack<int> &station, queue<int> &in, int n){
    int currCoache = 1;
    while(currCoache <= n){
        station.push(currCoache);
        while(!station.empty() && station.top() == in.front()){
            station.pop();
            in.pop();
        }
        currCoache++;
    }
    if(in.empty()){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    clearQueue(in);
    clearStack(station);
}

int main(){

    int n, data;
    int countN = 0;
    cin >> n;

    stack<int> station;
    queue<int> in;
    while(true){
        if(n!=0){
            countN = 0;
            for(int i = 0 ; i<n ; i++){
                cin >> data;
                if(data == 0){
                    break;
                } 
                else{
                    in.push(data);
                }
            }
            if(data == 0){
                n = 0;
                continue;
            }
            rails(station,in,n);
        }
        else{
            countN++;
            if(countN == 2){
                break;
            }
            cout << endl;
            cin >> n;
        }
    }
    return 0;
}