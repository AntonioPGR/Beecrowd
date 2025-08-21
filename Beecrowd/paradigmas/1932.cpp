#include <bits/stdc++.h>

using namespace std;

int n, c;
vector<int> prices;
vector<vector<int>> memo;

int calculate(int cur_day, int bough_day, int n, int total_profit){
  int next_day = cur_day + 1;
  if(cur_day == n) return total_profit;

  

  if(bough_day == -1) return max(
    calculate(next_day, cur_day, n, (total_profit - prices[cur_day] - c )), // COMPRAR
    calculate(next_day, bough_day, n, total_profit) // ESPERAR
  );

  return max(
    calculate(next_day, -1, n, (total_profit + prices[cur_day])), // VENDER
    calculate(next_day, bough_day, n, total_profit) // ESPERAR
  );
}

int main(){

  cin >> n >> c;
  prices.resize(n);
  for(int i = 0; i < n; i++) cin >> prices[i];

  memo = vector<vector<int>>(n, vector<int>(n, -1));

  cout << calculate(0, -1, n, 0) << endl;
}