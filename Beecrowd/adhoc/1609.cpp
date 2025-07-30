#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin >> t;
  while(t--){

    int n;
    cin >> n;

    unordered_map<int, bool> sheeps;
    int s, count = 0;
    for(int i = 0; i < n; i++){
      cin >> s;
      if(!sheeps.count(s)){
        sheeps[s] = true;
        count++;
      }
    }

    cout << count << endl;

  }

  return 0;
}