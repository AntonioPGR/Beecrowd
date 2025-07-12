#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool bfs(int s, int t, vector<int>& parent, vector<vector<int>>& adj) {
  fill(parent.begin(), parent.end(), -1);
  parent[s] = -2;
  queue<pair<int, int>> q;
  q.push({s, INT_MAX});
  while (!q.empty()) {
    int u = q.front().first;
    int flow = q.front().second;
    q.pop();
    for (int v = 0; v < adj.size(); v++) {
      if (parent[v] == -1 && adj[u][v] > 0) {
        parent[v] = u;
        int new_flow = min(flow, adj[u][v]);
        if (v == t) return true;
        q.push({v, new_flow});
      }
    }
  }
  return false;
}

int fordFulkerson(vector<vector<int>>& adj, int s, int t) {
  int max_flow = 0;
  vector<int> parent(adj.size());
  while (bfs(s, t, parent, adj)) {
    int path_flow = INT_MAX;
    for (int v = t; v != s; v = parent[v]) {
      int u = parent[v];
      path_flow = min(path_flow, adj[u][v]);
    }
    for (int v = t; v != s; v = parent[v]) {
      int u = parent[v];
      adj[u][v] -= path_flow;
      adj[v][u] += path_flow;
    }
    max_flow += path_flow;
  }
  return max_flow;
}


int getNumeroCamisa(string str){
  if(str == "XXL") return 2;
  else if(str == "XL") return 3;
  else if(str == "L") return 4;
  else if(str == "M") return 5;
  else if(str == "S") return 6;
  else if(str == "XS") return 7;
}

/* Lista de adj
0 -> Source ( liga do 8 ao M )
1 -> Sink
2 -> XXL 
3 -> XL 
4 -> L 
5 -> M 
6 -> S 
7 -> XS 
( camisas ligam no sink )
8 a M -> funcionarios ( liga no numero da camisa )
para 3 funcionarios -> 8 9 10
*/

int main(){
  int t;
  cin >> t;
  while(t--){
    
    int n, m;
    cin >> n >> m;

    int source = 0;
    int sink = 1;

    vector<vector<int>> adj(8+m, vector<int>(8+m, 0));
    for(int i = 2; i < 8; i++){
      adj[i][sink] = n/6;
    }

    string c1, c2;
    for(int i = 0; i < m; i++){
      cin >> c1 >> c2;
      int nc1 = getNumeroCamisa(c1);
      int nc2 = getNumeroCamisa(c2);
      int func = 8 + i;
      adj[func][nc1] = 1;
      adj[func][nc2] = 1;
      adj[source][func] = 1;
    }

    int result = fordFulkerson(adj, source, sink);

    if(result == m) cout << "YES" << endl;
    else cout << "NO" << endl;

  }
  return 0;
}