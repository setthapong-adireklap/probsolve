#include <iostream>
#include <map>

using namespace std;

int main(){

    int m;
    cin >> m;
    
    map<int,int> product;
    int mode, A, B;
    for(int i = 0 ; i<m ; i++){
        cin >> mode;
        switch(mode){
        case 1:
            cin >> A >> B;
            product[A] += B;
            break;
        case 2:
            cin >> A;
            cout << product[A] << endl;
            break;
        case 3:
            cin >> A >> B;
            if(product[A]-B >= 0){
                product[A] -= B;
                cout << B;
            }
            else{
                cout << product[A];
                product[A] = 0;
            }
            cout << endl;
            break;
        }
    }

    return 0;
}