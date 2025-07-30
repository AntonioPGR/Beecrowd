#include <bits/stdc++.h>

using namespace std;

int main(){

  int s, e;
  cin >> s >> e;

  int result = 24 - s + e;
  if(result > 24) result -= 24;

  cout << "O JOGO DUROU " << result << " HORA(S)" << endl;

  return 0;
}