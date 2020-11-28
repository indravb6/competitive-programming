#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <math.h>

#define ll long long

#define MAXN 100005
#define MAXLOG 20
#define MOD 1000000007

using namespace std;

int n, m, q, a, b, val[MAXN], low[MAXN], v;
bool vis[MAXN];
vector<int> e[MAXN];
int P[MAXN+5][MAXLOG+5], parent[MAXN+5], level[MAXN], bridge[MAXN];
bool is_bridge[MAXN];

void LCA_preprocess(){
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < MAXLOG; ++j) {
      P[i][j] = -1; 
    }
  }

  for (int i = 0; i < n; ++i) {
    P[i][0] = parent[i]; 
  }

  for (int j = 1; (1<<j) < n; ++j) {
    for (int i = 0; i < n; ++i) {
      if (P[i][j-1] != -1) {
        P[i][j] = P[P[i][j-1]][j-1] ; 
      }
    }
  }
}


int LCA(int u , int v){
  if (level[u] < level[v]) swap(u,v);     

  int dist = level[u] - level[v]; 
  while (dist > 0) {
    int raise_by = log2(dist);
    u = P[u][raise_by];
    dist -= (1<<raise_by) ; 
  }

  if (u == v) return u; 
  
  for (int j = MAXLOG; j >= 0; --j) {
    if ((P[u][j] != -1) and (P[u][j] != P[v][j])) {
      u = P[u][j]; 
      v = P[v][j]; 
    }
  }

  return parent[u];
}   

void dfs(int pos, int lvl, int par) {
  vis[pos] = true;
  low[pos] = val[pos] = ++v;
  level[pos] = lvl;
  for (int nx : e[pos]) {
    if (nx == par) continue;
    if (!vis[nx]) {
      parent[nx] = pos;
      dfs(nx, lvl + 1, pos);
      low[pos] = min(low[pos], low[nx]);
      if (low[nx] > val[pos]) is_bridge[nx] = true;
    } else {
      low[pos] = min(low[pos], val[nx]);
    }
  }
}

void prefix_sum(int pos) {
  vis[pos] = true;
  if (pos) bridge[pos] = bridge[parent[pos]] + (is_bridge[pos] ? 1 : 0);
  for (int nx : e[pos]) {
    if (vis[nx]) continue;
    prefix_sum(nx);
  }
}


int main() {
  ios_base::sync_with_stdio(0);

  cin >> n >> m >> q;
  for (int i = 0 ; i < m; i++) {
    cin >> a >> b; a--; b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  for (int i = 0; i < MAXN; i++) {
    parent[i] = -1;
  }

  dfs(0, 0, -1);

  for (int i = 0; i < MAXN; i++) {
    vis[i] = false;
  }

  prefix_sum(0);
  LCA_preprocess();

  while (q--) {
    cin >> a >> b; a--; b--;

    int l = LCA(a, b);
    if (l == a || l == b) {
      if (l == a && bridge[b] - bridge[a] == 0) cout << "YES\n";
      else if (l == b && bridge[a] - bridge[b]  == 0) cout << "YES\n";
      else cout << "NO\n";
    } else {
      if (bridge[a] - bridge[l] == 0 &&  bridge[b] - bridge[l] == 0) cout << "YES\n";
      else cout << "NO\n";
    }
  }

  return 0;
}