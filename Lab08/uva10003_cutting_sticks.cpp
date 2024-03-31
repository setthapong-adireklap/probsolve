#include <bits/stdc++.h>

using namespace std;

int l,n;
vector<int> arr;

void findMinimal(){
    
}

int main(){

    int data,total;
    do{
        cin >> l;
        if(l == 0){
            continue;
        }
        cin >> n;
        for(int i = 0 ; i<n ; i++){
            cin >> data;
            arr.push_back(data);
        }
        total = 0;
        cout << "The minimum cutting is " << total << "." << endl;
        arr.clear();
    }while(l != 0);

    return 0;   
}