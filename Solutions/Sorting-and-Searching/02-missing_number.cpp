#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  vector<int> b(m);
  for (auto &x : b) {
    cin >> x;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ans = 0;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < m && b[j] < a[i] - k) {
      j++;
    }
    if (j < m && b[j] <= a[i] + k) {
      ans++, j++;
    }
  }
  cout << ans;
}
