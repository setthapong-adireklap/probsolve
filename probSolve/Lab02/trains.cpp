#include <iostream>
#include <map>
#include <list>

using namespace std;

int main(){

    map<int,list<int>> dataList;
    int m, in1, in2;
    char f;
    cin >> m;

    for(int i = 0 ; i<m ; i++){
        cin >> f >> in1 >> in2;
        switch(f){
        case 'N':
            dataList[in2].push_back(in1);
            break;
        case 'M':
            dataList[in2].splice(dataList[in2].end(),dataList[in1]);
            break;
        } 
    }

    for(auto i = dataList.begin() ; i != dataList.end(); i++){
        for(auto j = (i->second).begin() ; j != (i->second).end() ; j++){
            cout << *j << endl;
        }
    }

    return 0;
}