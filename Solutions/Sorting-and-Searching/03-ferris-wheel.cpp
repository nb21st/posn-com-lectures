#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());

  int ans = 0;
  for (int i = 0, j = n - 1; i < j; i++) {
    while (i < j && a[i] + a[j] > x)
      --j;
    if (i >= j)
      break;
    ++ans;
    --j;
  }
  cout << n - ans;
}
