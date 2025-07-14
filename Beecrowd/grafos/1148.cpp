#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dfs(
  int u, 
  vector<vector<int>> &adj, 
  vector<int> &index, 
  vector<int> &lowlink, 
  vector<bool> &onStack, 
  stack<int> &stk, 
  int &idx, 
  vector<vector<int>> &sccs
) {
  index[u] = lowlink[u] = idx++;
  stk.push(u);
  onStack[u] = true;
  int n = adj[0].size();
  for (int v = 0; v < n; v++) {
    if(adj[u][v] == -1) continue;
    if (index[v] == -1) {
      dfs(v, adj, index, lowlink, onStack, stk, idx, sccs);
      lowlink[u] = min(lowlink[u], lowlink[v]);
    } else if (onStack[v]) {
      lowlink[u] = min(lowlink[u], index[v]);
    }
  }
  if (lowlink[u] == index[u]) {
    vector<int> scc;
    int v;
    do {
      v = stk.top();
      stk.pop();
      onStack[v] = false;
      scc.push_back(v);
    } while (v != u);
    sccs.push_back(scc);
  }
}

vector<vector<int>> tarjansSCC(vector<vector<int>> &adj, int n) {
  vector<int> index(n, -1);
  vector<int> lowlink(n, -1);
  vector<bool> onStack(n, false);
  stack<int> stk;
  vector<vector<int>> sccs;
  int idx = 0;
  for (int i = 0; i < n; ++i) {
    if (index[i] == -1) {
      dfs(i, adj, index, lowlink, onStack, stk, idx, sccs);
    }
  }
  return sccs;
}

vector<int> dijkstra(vector<vector<int>> &adj, int n, int src) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  vector<int> dist(n, INT_MAX);
  dist[src] = 0;
  pq.push({0, src});
  while (!pq.empty()) {
    int curr_dist = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    for (int v = 0; v < n; v++){
      if(adj[u][v] == -1) continue;
      int weight = adj[u][v];
      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
}


int main(){
  int n, e;
  while(cin >> n >> e && n != 0){
    vector<vector<int>> adj(n, vector<int>(n, -1));
    int x, y, h;
    for(int i = 0; i < e; i++){
      cin >> x >> y >> h;
      adj[x-1][y-1] = h;
    }
    vector<vector<int>> sccs = tarjansSCC(adj, n);

    for(vector<int> scc : sccs){
      for(int x : scc){
        for(int y : scc){
          adj[x][y] = 0;
        }
      }
    }

    vector<vector<int>> dijkstras(n, vector<int>(0));
    int k, o, d;
    cin >> k;
    while(k--){
      cin >> o >> d;
      o--;
      d--;
      if(dijkstras[o].size() == 0){
        dijkstras[o] = dijkstra(adj, n, o);
      }
      int result = dijkstras[o][d];
      if(result == INT_MAX) cout << "Nao e possivel entregar a carta" << endl;
      else cout << dijkstras[o][d] << endl;
    }
    cout << endl;

  }
}