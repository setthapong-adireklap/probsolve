#include <iostream>

using namespace std;

int main(){

  int n;
  int m = 0;

  cin >> n;
  for(int i = 0 ; i<n ; i++){
    int x;
    cin >> x;
    if(x >= 0){
      m += x;
    }
  }

  cout << m << endl;
  
  return 0;
}