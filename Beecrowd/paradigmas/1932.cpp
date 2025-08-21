#include <bits/stdc++.h>

using namespace std;


int main(){

  int n, c;
  cin >> n >> c;

  vector<int> values(n);
  for(int i = 0; i < n; i++) cin >> values[i];

  vector<vector<int>> dp(n+1, vector<int>(2, 0));

  for(int day = n - 1; day >= 0; day--){
    dp[day][0] = max(
      dp[day + 1][1] - c - values[day],
      dp[day + 1][0]
    );
    dp[day][1] = max(
      dp[day + 1][0] + values[day],
      dp[day + 1][1]
    );
  }

  cout << dp[0][0] << endl;

}