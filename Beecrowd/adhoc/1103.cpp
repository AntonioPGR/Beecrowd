#include <bits/stdc++.h>

using namespace std;

int main(){

  int h1, m1, h2, m2;
  while(cin >> h1 >> m1 >> h2 >> m2 && (h1 != 0 || m1 != 0 || h2 != 0 || m2 != 0)){

    int start = h1 * 60 + m1;
    int end = h2 * 60 + m2;

    if(end <= start) end += 24 * 60;

    cout << end - start << endl;
  }


  return 0;
}