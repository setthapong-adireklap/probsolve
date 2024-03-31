#include <iostream>
#include <string>

using namespace std;

int main(){

    int x = 0, y = 0;
    string direction;

    cin >> direction;
    for(char a : direction){
        switch(a){
        case 'N':
            y += 1;
            break;
        case 'S':
            y -= 1;
            break;
        case 'E':
            x += 1;
            break;
        case 'W':
            x -= 1;
            break;
        case 'Z':
            x = 0;
            y = 0;
            break;
        default:
            break;
        }
    }
    cout << x << " " << y << "\n";

    return 0;
}