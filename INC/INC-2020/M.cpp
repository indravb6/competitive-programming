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

int n, ans, tmp;
bool v[MAXN];

int main() {
  ios_base::sync_with_stdio(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    while (tmp) {
      if (i && !v[i-1]) v[i-1] = 1;
      else if (!v[i]) v[i] = 1;
      else if (i+1 < n && !v[i+1]) v[i+1] = 1;
      else break;
      ans++; tmp--;
    }
  }

  cout << ans << "\n";

  return 0;
}