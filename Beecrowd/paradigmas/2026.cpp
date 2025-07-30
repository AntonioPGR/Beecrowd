#include <bits/stdc++.h>

using namespace std;

int knapsack(int w_max, vector<int> &v, vector<int> &w) {
  vector<int> dp(w_max + 1, 0);
  for (int i = 0; i < w.size(); i++) {
    for (int j = w_max; j >= w[i]; j--) {
      dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
    }
  }
  return dp[w_max];
}


int main(){

  int g;
  cin >> g;
  for(int i = 0; i < g; i++){

    int p, w;
    cin >> p >> w;

    vector<int> values(p), weights(p);
    int e, pc;
    for(int j = 0; j < p; j++) cin >> values[j] >> weights[j];

    cout << "Galho " << i + 1 << ":" << endl;
    cout << "Numero total de enfeites: " << knapsack(w, values, weights) << endl << endl;

  }

  return 0;
}