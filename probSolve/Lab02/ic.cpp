#include <iostream>
#include <list>

using namespace std;

int main(){

    list<int> dataList;
    int n, data;
    string m;
    cin >> n;

    for(int i = 0 ; i<n ; i++){
        cin >> m;
        if(m == "li"){
            cin >> data;
            dataList.push_front(data);
        }
        else if(m == "ri"){
            cin >> data;
            dataList.push_back(data);
        }
        else if(m == "lr"){
            dataList.push_back(dataList.front());
            dataList.pop_front();
        }
        else if(m == "rr"){
            dataList.push_front(dataList.back());
            dataList.pop_back();
        }
    }

    for(auto i = dataList.begin() ; i != dataList.end() ; i++){
        cout << *i  << endl;
    }

    return 0;
}