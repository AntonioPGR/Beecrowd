#include <bits/stdc++.h>

using namespace std;

int main(){

  regex password_pattern(R"(^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)[A-Za-z\d]{6,32}$)");

  string s;
  while(getline(cin, s)){
    if(regex_match(s, password_pattern)) cout << "Senha valida." << endl;
    else cout << "Senha invalida." << endl;
  }
  return 0;
}