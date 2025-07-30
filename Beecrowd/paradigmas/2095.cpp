#include <bits/stdc++.h>

using namespace std;

int main(){

  int s;
  cin >> s;

  vector<int> enemy(s);
  for(int i = 0; i < s; i++){
    cin >> enemy[i];
  };

  multiset<int> arm;
  int temp;
  for(int i = 0; i < s; i++){
    cin >> temp;
    arm.insert(temp);
  };

  int battle_counts = 0;
  for(int i = 0; i < s; i++){
    auto it = arm.upper_bound(enemy[i]);
    if (it != arm.end()){
      battle_counts++;
      arm.erase(it);
    }
  }

  cout << battle_counts << endl;

  return 0;
}