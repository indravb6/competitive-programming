#include <iostream>
#define MAXN 105

using namespace std;

int n, a[MAXN], b[MAXN], res;

int main() {

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (a[i] > b[i]) res += 3;
    else if (a[i] == b[i]) res++;
  }

  cout << res << "\n";

  return 0;
}