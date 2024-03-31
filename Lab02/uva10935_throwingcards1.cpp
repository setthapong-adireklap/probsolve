#include <iostream>
#include <list>

using namespace std;

void remain(int n){

    list<int> cardRemain;
    for(int i = 0 ; i<n ; i++){
        cardRemain.push_back(i+1);
    }

    if(n==1){
        cout << "Discarded cards:" << endl;
    }
    else{
        cout << "Discarded cards: ";
    }
    while(cardRemain.size() != 1){
        if(cardRemain.size() == 2){
            cout << cardRemain.front() << endl;
        }
        else{
            cout << cardRemain.front() << ", ";
        }
        cardRemain.pop_front();
        cardRemain.push_back(cardRemain.front());
        cardRemain.pop_front();
    }
    cout << "Remaining card: " << cardRemain.front() << endl;
}

int main(){

    int n;
    
    do{
        cin >> n;
        if(n==0){
            break;
        }
        else{
            remain(n);
        }
    } while(true);
    
    return 0;
}