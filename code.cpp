#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define file "input"

const int INF = 1e9;
int n, dp[2][3][3];
char trans[256][3];
string s;

void minimize(int &a, int b) {
  if (a > b) a = b;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> s;
    n = s.size();

    if (n == 1) {
      cout << 0;
      return 0;
    }

    foru(i, 'a', 'z') {
      int j = (int)i;
      trans[j][0] = i;
      trans[j][1] = i+1;
      if (trans[i][1] > 'z') trans[i][1] = 'a';
      trans[j][2] = i-1;
      if (trans[i][2] < 'a') trans[i][2] = 'z';
    }

    int cur = 0, nxt = 1;
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0][0] = 0;
    dp[1][0][1] = dp[1][0][2] = 1;
    foru(c, 0, 2)
      foru(p, 0, 2)
        if (trans[s[1]][c] != trans[s[0]][p])
          minimize(dp[0][p][c], dp[1][0][p] + (c > 0));

    foru(i, 2, n-1) {
      memset(dp[nxt], 0x3f, sizeof(dp[nxt]));
      foru(c, 0, 2) {
        foru(pv, 0, 2) if (trans[s[i]][c] != trans[s[i-2]][pv]) {
          foru(p, 0, 2) if (trans[s[i]][c] != trans[s[i-1]][p] && dp[cur][pv][p] < INF) {
            minimize(dp[nxt][p][c], dp[cur][pv][p] + (c > 0));
          }
        }
      }
      cur ^= 1;
      nxt ^= 1;
    }

//  cout << 0;
    int ans = INF;
    foru(i, 0, 2) foru(j, 0, 2) minimize(ans, dp[cur][i][j]);
    cout << ans;
    return 0;
}
