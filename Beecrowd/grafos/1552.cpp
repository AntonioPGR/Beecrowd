#include <iostream>
#include <bits/stdc++.h>

using namespace std;

double calculateDistance(pair<double, double> a, pair<double, double> b){
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double spanningTree(vector<vector<double>> &adj, int n_vertices) {
  // Pair: peso da aresta e vertice de destino
  priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
  vector<bool> visited(n_vertices, false);
  double res = 0;
  pq.push({0, 0});
  while(!pq.empty()){
    pair<double, int> p = pq.top();
    double wt = p.first;
    int u = p.second;
    pq.pop();
    if(visited[u]) continue;
    res += wt;
    visited[u] = true;
    for(int v = 0; v < n_vertices; v++){
      if(adj[u][v] != 0 && visited[v] == false) pq.push({adj[u][v], v});
    }
  }
  return res;
}

int main(){
  int c;
  cin >> c;
  while(c--){
    int n;
    cin >> n;
    vector<pair<double, double>> nodes(n);
    for(int i = 0; i < n; i++) cin >> nodes[i].first >> nodes[i].second;
    vector<vector<double>> adj(n, vector<double>(n));
    for(int i = 0; i < n; i++){
      for(int j = i; j < n; j++){
        double distance = 0;
        if(i != j) distance = calculateDistance(nodes[i], nodes[j]);
        adj[i][j] = distance;
        adj[j][i] = distance;
      }
    }
    double result = spanningTree(adj, n) / 100;
    cout << fixed << setprecision(2) << result << endl;
  }
}