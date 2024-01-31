#include <iostream>
#include <set>

using namespace std;

int main(){

    int n,m;
    cin >> n >> m;
    
    set<int> setX;
    int x;
    for(int i = 0 ; i<n ; i++){
        cin >> x;
        setX.insert(x);
    }

    int yIn, res, value1, value2;
    set<int>::iterator left, right;
    for(int i = 0 ; i<m ; i++){
        cin >> yIn;
        
        right = setX.lower_bound(yIn);
        left = right;
        --left;

        if(right == setX.end()){
            res = *left;
        }
        else if(right == setX.begin()){
            res = *right;
        }
        else{
            value1 = abs(yIn - (*left));
            value2 = abs(yIn - (*right));
            if(value1 <= value2){
                res = *left;
            }
            else{
                res = *right;
            }
        }
        cout << res << endl;
    }

    return 0;
}