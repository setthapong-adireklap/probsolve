#include <bits/stdc++.h>
#define MAX_SIZE 22

using namespace std;

int data_in[MAX_SIZE];
int rot[MAX_SIZE];
int n, s;

void print() {
  int count = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      cout << rot[i + 5 * (count)] << " ";
      count = (count + 1) % 4;
    }
  }
  cout << endl;
}

int main() {

  cin >> n >> s;

  for (int i = 0; i < n; i++) {
    cin >> data_in[i];
  }
  if (n < 20) {
    int count = 1;
    for (int i = n; i < 20; i++) {
      data_in[i] = count;
      count++;
    }
  }

  for (int i = 0; i < 20; i++) {
    rot[(i + s) % 20] = data_in[i];
  }
  print();

  return 0;
}
