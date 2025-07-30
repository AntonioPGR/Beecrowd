#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, k;
  while(cin >> n >> k){
    
    vector<int> diffs;
    int last = 0, cur = -1;
    for(int i = 0; i < n-1; i++){
      cin >> cur;
      diffs.push_back(cur - last);
      last = cur;
    }

    sort(diffs.rbegin(), diffs.rend());
    diffs.erase(diffs.begin(), diffs.begin() + (k - 1));
    int result = accumulate(diffs.begin(), diffs.end(), 0);

    cout << result << endl;

  }

  return 0;
}