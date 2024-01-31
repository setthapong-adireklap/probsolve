#include <iostream>
#include <list>

using namespace std;

int main(){

    list<int> dataList;
    list<int>::iterator it; 
    int n, data;
    char m;

    cin >> n;
    for(int i = 0 ; i<n ; i++){
        cin >> m >> data;
        switch(m){
        case 'I':
            dataList.push_front(data);
            break;
        case 'D':
            if(data <= 20 && data >= 1 && data <= dataList.size()){
                it = dataList.begin(); 
                advance(it,data-1); 
                dataList.erase(it);
            }
            break;
        default:
            break;
        }
    }

    for(auto i = dataList.begin() ; i != dataList.end() ; i++){
        cout << *i << endl;
    }

    return 0;
}