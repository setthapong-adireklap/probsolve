#include <iostream>
#include <list>

using namespace std;

int main(){
    
    string massage;
    list<char> textRes;
    list<char>::iterator it;

    while(getline(cin,massage)){
        textRes.clear();
        it = textRes.begin();
        for(int i = 0 ; i<massage.size() ; i++){
            if(massage[i] == '['){
                it = textRes.begin();
            }
            else if(massage[i] == ']'){
                it = textRes.end();
            }
            else{
                textRes.insert(it,massage[i]);
            }
        }
        
        for(auto k = textRes.begin(); k != textRes.end() ; k++){
            cout << *k ;
        }
        cout << "\n";
    }
    return 0;
}