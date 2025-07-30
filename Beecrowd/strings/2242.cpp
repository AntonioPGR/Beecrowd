#include <bits/stdc++.h>

using namespace std;

int main(){

  string line;
  getline(cin, line);

  string clean = "";
  for(char c : line){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      clean += c;
  }

  bool is_palindrome = true;
  for(int i = 0, j = clean.size() - 1; i < j; i++, j--){
    if(clean[i] != clean[j]){
      is_palindrome = false;
      break;
    }
  }

  if(is_palindrome) cout << "S" << endl;
  else cout << "N" << endl;

}