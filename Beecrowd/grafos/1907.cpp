#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void floodFill(vector<vector<int>>& image, int line, int column, int line_max, int col_max, int color) {
  if(image[line][column] == color) return;
  vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  queue<pair<int, int>> q;
  q.push({line, column});
  image[line][column] = color;
  while(!q.empty()){
    pair<int, int> cur = q.front();
    q.pop();
    for(pair<int, int> dir : directions){
      int next_line = cur.first + dir.first;
      int next_column = cur.second + dir.second;
      if(next_line >= 0 && next_line < line_max && next_column >= 0 && next_column < col_max && image[next_line][next_column] == 0){
        image[next_line][next_column] = color;
        q.push({next_line, next_column});
      }
    }
  }
}

int getColorAmount(vector<vector<int>>& image, int n, int m){
  int count = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(image[i][j] == 0) {
        count++;
        floodFill(image, i, j, n, m, count);
      }
    }
  }
  return count;
}

int main(){
  int n, m;
  cin >> n >> m;
  cin.clear();
  cin.ignore();

  // 0: branco, -1: preto, n: cor;
  vector<vector<int>> image(n, vector<int>(m, 0));
  string line;
  for(int i = 0; i < n; i++){
    getline(cin, line);
    for(int j = 0; j < m; j++){
      if(line[j] == 'o') image[i][j] = -1;
    }
  }

  int result = getColorAmount(image, n, m);
  cout << result << endl;

  return 0;
}