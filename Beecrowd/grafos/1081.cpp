#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dfsRec(vector<vector<int>>& adj, vector<bool>& visited, int cur, int depth){
  visited[cur] = true;
  sort(adj[cur].begin(), adj[cur].end());
  for(int v : adj[cur]){
    for(int i = 0; i < depth; i++) cout << "  ";
    cout << cur << "-" << v;
    if(!visited[v]){
      cout << " pathR(G," << v << ")" << endl;
      dfsRec(adj, visited, v, depth + 1);
    } else cout << endl;
  }
}

void printDFS(vector<vector<int>>& adj, int n){
  vector<bool> visited(n, false);
  for(int i = 0; i < n; i++){
    if(!visited[i] && adj[i].size() > 0){
      sort(adj[i].begin(), adj[i].end());
      dfsRec(adj, visited, i, 1);
      cout << endl;
    }
  }
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int v, e;
    cin >> v >> e;

    int x, y;
    vector<vector<int>> adj(v, vector<int>());
    for(int j = 0; j < e; j++){
      cin >> x >> y;
      adj[x].push_back(y);
    }

    cout << "Caso " << i+1 << ":" << endl;
    printDFS(adj, v);
  }
  return 0;
}