#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,d,r;

int main(){

    int a,b, total;
    vector<int> A;
    vector<int> B;
    while(true){
        cin >> n >> d >> r;
        if(!n && !d && !r){
            break;
        }
        for(int i = 0 ; i < n ; i++){
            cin >> a ;
            A.push_back(a);
        }
        sort(A.begin(),A.end());
        for(int i = 0 ; i < n ; i++){
            cin >> b;
            B.push_back(b);
        }
        sort(B.begin(),B.end(),greater<int>());

        total = 0;
        for(int i = 0 ; i < n ; i++){
            if(A[i]+B[i] > d){
                total += A[i]+B[i]-d;
            }
        }
        cout << total*r << endl;
        A.clear();
        B.clear();
    }

    return 0;
}