#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int n, int src) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  vector<int> dist(n, INT_MAX);
  dist[src] = 0;
  pq.push({0, src});
  while (!pq.empty()) {
    int curr_dist = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    for (auto &x : adj[u]) {
      int v = x.first;
      int weight = x.second;
      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
}

int main(){
  int n, m, c, k;
  while(cin >> n >> m >> c >> k && n != 0){
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    int u, v, p;
    for(int i = 0; i < m; i++){
      cin >> u >> v >> p;
      adj[u].push_back({v, p});
      adj[v].push_back({u, p});
    }

    int goal = c-1;
    for(int i = 0; i < goal; i++){
      int next = i+1, p = 0, total = adj[i].size();
      for(int j = 0; j < total; j++){
        if(adj[i][j].first == next){
          p = adj[i][j].second;
          break;
        }
      }
      adj[i].clear();
      adj[i].push_back({next, p});
    }

    int result = dijkstra(adj, n, k)[goal];
    cout << result << endl;
  }
}