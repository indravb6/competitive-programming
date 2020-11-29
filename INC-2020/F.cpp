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

int n, k;
string s;

bool canChar(int x, char c) {
  int l = 0;
  int ubah = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != c) ubah++;

    while (ubah > x) {
      if (s[l] != c) ubah--;
      l++;
    }

    if (i - l + 1 == k) {
      return true;
    }
  }
  return false;
}

bool can(int x) {
  for (char c = 'A'; c <= 'Z'; c++) {
    if (canChar(x, c)) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);

  cin >> n >> k;
  cin >> s;

  int l = 0;
  int r = n;
  int mid = (l + r) / 2;
  while (l < r) {
    if (can(mid)) r = mid;
    else l = mid + 1;
    mid = (l + r) / 2;
  }

  cout << mid << "\n";

  return 0;
}