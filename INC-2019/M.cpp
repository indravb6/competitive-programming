#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>

#define ll long long

#define MAXN 100005
#define MOD 1000000007

using namespace std;

ll fac[MAXN], x, y, res;

ll power(ll a, ll b) {
  if (b == 0) return 1;
  if (b == 1) return a % MOD;

  ll tmp = power(a, b >> 1);
  if (b & 1) return (((tmp * tmp) % MOD) * a) % MOD;
  else return (tmp * tmp) % MOD;
}

ll modIverse(ll n) {
  return power(n, MOD - 2);
} 

ll c(ll n, ll r) {
  ll tmp = (fac[n] * modIverse(fac[r])) % MOD;
  tmp = (tmp * modIverse(fac[n-r])) % MOD;
  return tmp;
}

int main() {
  fac[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fac[i] = (fac[i-1] * i) % MOD;
  }

  cin >> y >> x;
  for (int i = 0; i <= y/2; i++) {
    int j = y - i*2;
    if (j+i > x+1) continue;
    ll tmp = (c(x+1, i+j) * c(i+j, i)) % MOD; 
    res = (res + tmp) % MOD;
  }

  cout << res << "\n";

  return 0;
}