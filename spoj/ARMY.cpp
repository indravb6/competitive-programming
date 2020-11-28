#include <iostream>
#include <queue>

using namespace std;

int tc, ng, nm, tmp, tmp_a, tmp_b;
priority_queue<int> a, b;

int main() {
  cin >> tc;
  
  while (tc--) {
    cin >> ng >> nm;
    
    while (ng--) {
      cin >> tmp;
      a.push(tmp);
    }

    while (nm--) {
      cin >> tmp;
      b.push(tmp);
    }

    while (a.size() && b.size()) {
      tmp_a = a.top();
      tmp_b = b.top();

      if (tmp_a < tmp_b) {
        a.pop();
      } else {
        b.pop();
      }
    }

    if (!a.size()) cout << "MechaGodzilla\n";
    else cout << "Godzilla\n";

    while (a.size()) a.pop();
    while (b.size()) b.pop();
  }

  return 0;
}