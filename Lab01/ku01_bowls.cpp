#include <iostream>

using namespace std;

int main(){

  int freq[300] = {0};
  int n, x;
  int min_size = 0;

  cin >> n;
  for(int i = 0 ; i < n ; i++){
    cin >> x;
    freq[x-1] += 1;
    if(freq[x-1] > min_size){
      min_size = freq[x-1];
    }
  }

  cout << min_size << endl;
  
  return 0;
}