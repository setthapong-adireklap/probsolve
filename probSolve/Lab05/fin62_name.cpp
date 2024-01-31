#include <iostream>

using namespace std;

int main(){

    string name, message;
    int currPos = 0;
    cin >> name;
    int n = name.size();
    cin >> message;

    int result = 0;
    for(char a : message){
        if(a == name[currPos]){
            currPos = (currPos+1) % n;
            if(currPos == 0){
                result++;
            }
        }
    }
    cout << result << endl;

    return 0;
}