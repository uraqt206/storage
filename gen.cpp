#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

void setIO() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen("input.inp", "r")) {
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "w", stdout);
  }
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
  return l + rng() % (r - l + 1);
}

int n, m, q;

int main() {
  setIO();
  int n = rnd(20, 100);
  foru(i, 1, n) {
    cout << char(rng() % 26 + 'a');
  }
}
