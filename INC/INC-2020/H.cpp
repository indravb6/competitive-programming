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
#define MOD 1000000007

using namespace std;

int n, s[MAXN], m, b[MAXN];
bool vis[MAXN];
int sg[MAXN*4+10];

void build(int id, int l, int r) {
  if (l == r) {
    sg[id] = l;
  } else {
    int m = (l + r)/2;
    build(2*id + 1, l, m);
    build(2*id + 2, m+1, r);

    if (b[sg[2*id + 1]] == b[sg[2*id + 2]]) {
      sg[id] = min(sg[2*id + 1], sg[2*id + 2]);
    } else if (b[sg[2*id + 1]] > b[sg[2*id + 2]]) {
      sg[id] = sg[2*id + 1];
    } else {
      sg[id] = sg[2*id + 2];
    }
  }
}

int query(int id, int l, int r, int x, int y) {
  if ((x <= l) && (r <= y)) {
    return sg[id];
  } else {
    int m = (l + r)/2;
    int ans = -1;

    if (x <= m) {
      ans = query(2*id + 1, l, m, x, y);
    }
    
    if (y > m) {
      int tmp = query(2*id + 2, m+1, r, x, y);
      if (ans == -1) ans = tmp;
      else {
        if (b[ans] == b[tmp]) {
          ans = min(ans, tmp);
        } else if (b[ans] < b[tmp]) {
          ans = tmp;
        }
      }
    } 
 
    return ans;
  }
}

void update(int id, int l, int r, int x, int v) {
  if (l == r) {
    sg[id] = v;
  } else {
    int m = (l + r)/2;
    if (x <= m) update(2*id + 1, l, m, x, v);
    if (x > m)  update(2*id + 2, m+1, r, x, v);
 
    if (b[sg[2*id + 1]] == b[sg[2*id + 2]]) {
      sg[id] = min(sg[2*id + 1], sg[2*id + 2]);
    } else if (b[sg[2*id + 1]] > b[sg[2*id + 2]]) {
      sg[id] = sg[2*id + 1];
    } else {
      sg[id] = sg[2*id + 2];
    }
  }
}


int main() {
  ios_base::sync_with_stdio(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  int res = 0;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  build(0, 0, m-1);
  for (int i = 0; i < n; i++) {
    int j = m-1;
    bool f = false;
    while (j >= 0) {
      int ambil = query(0, 0, m-1, 0, j);
      if (b[ambil] < s[i]) break;
      j = ambil - 1;
      b[ambil] = -1;
      update(0, 0, m-1, ambil, ambil);
      if (!f) {
        f = true;
        res++;
      }
    }
  }

  cout << res << "\n";

  return 0;
}