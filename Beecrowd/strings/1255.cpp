#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;
  cin.ignore();
  cin.clear();

  while(n--){

    string line;
    getline(cin, line);

    map<char, int> freq;
    for(char c : line){
      if(isalpha(c)) {
        c = tolower(c);
        freq[c]++;
      }
    }

    int max_freq = 0;
    for(auto [ch, count] : freq){
      max_freq = max(max_freq, count);
    }

    for(auto [ch, count] : freq){
      if(count == max_freq)
        cout << ch;
    }
    cout << endl;

  }

  return 0;
}
