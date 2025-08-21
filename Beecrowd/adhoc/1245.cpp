#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  while(cin >> n){

    vector<pair<int, int>> shoes(31, {0, 0});

    int m;
    char l;
    for(int i = 0; i < n; i++){
      cin >> m >> l;
      m -= 30;
      if(l == 'E') shoes[m].first += 1;
      else shoes[m].second += 1;
    }

    int count = 0;
    for(int i = 0; i <= 30; i++){
      count += min(shoes[i].first, shoes[i].second);
    }

    cout << count << endl;

  }

  return 0;
}