#include <iostream>

using namespace std;

int main(){

  int n;
  int score = 0;
  
  cin >> n;
  for(int i = 0; i < n; i++){
    int x,y;
    cin >> x >> y;
    int d2 = x*x + y*y;
    if(d2 <= 4){
      score += 5;
    }
    else if(d2 <= 16){
      score += 4;
    }
    else if(d2 <= 36){
      score += 3;
    }
    else if(d2 <= 64){
      score += 2;
    }
    else if(d2 <= 100){
      score += 1;
    }
  }

  cout << score << endl;
  
  return 0;
}