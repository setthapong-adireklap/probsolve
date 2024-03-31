#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

int main(){

    int n, in1, in2;
    cin >> n;

    int necklaceStatus[n];
    vector<forward_list<int>> necklace;

    for(int i = 0 ; i < n ; i++){
        necklace.push_back({i+1});
        necklaceStatus[i] = i;
    }
    
    forward_list<int>::iterator it;
    int temp;
    for(int i = 0 ; i < n-1 ; i++){
        cin >> in1 >> in2;
        for(auto k = necklace[necklaceStatus[in2-1]].begin() ; k != necklace[necklaceStatus[in2-1]].end() ; k++ ){
            if((*k) == in2){
                it = k;
                break;
            }
        }
        temp = necklaceStatus[in1-1];
        for(auto k = necklace[necklaceStatus[in1-1]].begin() ; k != necklace[necklaceStatus[in1-1]].end() ; k++ ){
            necklaceStatus[(*k)-1] = necklaceStatus[in2-1];
        }
        necklace[necklaceStatus[in2-1]].splice_after(it, necklace[temp]);
        
    }

    for(auto i = necklace[necklaceStatus[0]].begin() ; i != necklace[necklaceStatus[0]].end() ; i++ ){
        cout << *i << " ";
    }
    cout << '\n';

    return 0;
}