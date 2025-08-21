#include <bits/stdc++.h>

using namespace std;

int main(){

  string line;
  while(getline(cin, line)){
    
    stringstream ss(line);
    string word;
    int count = 0;
    char last_letter = ' ';
    char last_considered = ' ';
    while(ss >> word){
      char cur_letter = tolower(word[0]);
      if(last_letter == ' ' || last_letter != cur_letter){
        last_letter = cur_letter;
        last_considered = ' ';
        continue;
      }
      if(last_letter == cur_letter && last_considered == ' '){
        last_considered = cur_letter;
        count++;
      }
    }

    cout << count << endl;
  }

  return 0;
}
