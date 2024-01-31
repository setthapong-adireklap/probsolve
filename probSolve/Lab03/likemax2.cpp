#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main(){

    int n, mode, data;
    map<int,int> like;
    cin >> n;

    for(int i = 0 ; i<n ; i++){
        cin >> mode >> data;
        switch(mode){
        case 0:
            like[data] -= 1;
            break;
        
        case 1:
            like[data] += 1;
            break;
        }
    }

}
