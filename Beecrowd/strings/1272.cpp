#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;
  cin.clear();
  cin.ignore();

  string txt;
  while(n--){

    getline(cin, txt);

    char last_char = ' ';
    for(char c : txt){
      if(c != ' ' && last_char == ' ') cout << c;
      last_char = c;
    }
    cout << endl;

  }

  return 0;
}