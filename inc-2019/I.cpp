#include <iostream>
#include <string>
#include <stdio.h>

#define MAXN 100000

using namespace std;

int n;
string a, b;

int main() {
  cin >> n;
  cin >> a;
  cin >> b;

  int ans = 0;

  for (int i = 0; i < 26; i++) {
    char c = 'a' + i;
    int tmp = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] == c || b[j] == c) tmp++;
    }
    ans = max(ans, tmp);
  }

  cout << ans << "\n";

  return 0;
}