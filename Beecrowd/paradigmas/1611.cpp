#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin >> t;
  while(t--){

    int n, m, c;
    cin >> n >> c >> m;

    vector<int> floors(m);
    for(int i = 0; i < m; i++){
      cin >> floors[i];
    }
    sort(floors.rbegin(), floors.rend());

    int groups_amount = (m + c - 1) / c;
    vector<vector<int>> groups(groups_amount, vector<int>());
    for(int i = 0; i < groups_amount; i++){
      for(int j = 0; j < c; j++){
        int index = i * c + j;
        if(index >= m) break;
        groups[i].push_back(floors[index]);
      }
    }

    int price = 0;
    for(int i = 0; i < groups.size(); i++){
      price += 2 * groups[i][0];
    }

    cout << price << endl;

  }

  return 0;
}