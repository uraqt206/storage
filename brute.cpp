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
    freopen("input.inp", "r", stdin);
    freopen("input.out2", "w", stdout);
  }
}

const int INF = 1e9;
const int N = 1e4+5;

int n, dp[N][26][26];
int c[N];
string s;

void minimize(int &a, int b) {
  if (a > b) a = b;
}

int dist(char a, char b) {
  return min(abs(a - b), 26 - abs(a - b));
}

int main() {
  setIO();
  cin >> s;
  n = s.size();
  foru(i, 0, n-1) c[i] = s[i]-'a';

  if (n == 1) {
    cout << 0;
    return 0;
  }

  memset(dp, 0x3f, sizeof(dp));
  foru(i, 0, 25)
    foru(j, 0, 25) if (i != j)
      dp[2][i][j] = dist(i, c[0]) + dist(j, c[1]);

  foru(i, 2, n-1) {
    foru(x, 0, 25)
      foru(y, 0, 25) if (dp[i][x][y] < INF) {
        foru(z, 0, 25) if (z != x && z != y && x != y) {
          minimize(dp[i+1][y][z], dp[i][x][y] + dist(z, c[i]));
        }
      }
  }

//  cout << 0;
  int ans = INF;
  foru(i, 0, 25) foru(j, 0, 25) minimize(ans, dp[n][i][j]);
  cout << ans;
}
