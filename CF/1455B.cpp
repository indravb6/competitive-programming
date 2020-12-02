#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <math.h>

#define ll long long

#define MAXN 1000005
#define MOD 1000000007

using namespace std;

int t, tmp, sum[MAXN], mx;

int main() {
  ios_base::sync_with_stdio(0);

  for (int i = 1; i < MAXN; i++) {
    sum[i] = sum[i-1] + i;
    if (sum[i] >= MAXN) {
      mx = i;
      break;
    }
  }

  cin >> t;
  while (t--) {
    cin >> tmp;
    int l = 0;
    int r = mx;
    int mid = (l + r) / 2;
    while (l < r) {
      if (sum[mid] < tmp) l = mid + 1;
      else r = mid;
      mid = (l + r) / 2;
    }

    cout << ((sum[mid]-tmp == 1) ? (mid+1) : mid) << "\n";
  }

  return 0;
}