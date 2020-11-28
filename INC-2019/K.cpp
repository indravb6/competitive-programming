#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <math.h>

#define ll long long

#define MAXN 20005
#define MOD 1000000007

using namespace std;

int n, a, b, tmp;

int main() {
  ios_base::sync_with_stdio(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    if (tmp & 1) a++;
    else b++;
  }

  if (a >= b) cout << b + ((a-b) / 2) << "\n";
  else cout << a << "\n";

  return 0;
}