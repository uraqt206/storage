#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define fore(x, v) for(auto &x : v)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define file "input"

template<class T> bool minimize(T &a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> bool maximize(T &a, T b) { if (a < b) { a = b; return 1; } return 0; }

void setIO() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".inp", "r")) {
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 1e5+6;
const int MOD = 1e9+7;

int n, q, a[N];
vector<int> evts[N], adj[N];

int sub[N], high[N], par[N], who[N], head[N], st[N];

struct node {
  int lb, rb, ans;
  node() { lb = N; rb = -N; ans = N; }
} nul, sgt[N*4];

node comb(node a, node b) {
  node c;
  c.ans = min({a.ans, b.ans, b.lb - a.rb});
  c.lb = min(a.lb, b.lb);
  c.rb = max(a.rb, b.rb);
  return c;
}

void update(int i, int id = 1, int lb = 1, int rb = n) {
  if (lb ^ rb) {
    int k = id << 1, mb = (lb + rb) >> 1;
    if (i <= mb) update(i, id*2, lb, mb);
    else update(i, id*2+1, mb+1, rb);
    sgt[id] = comb(sgt[k], sgt[k+1]);
  }
  else {
    if (sgt[id].lb != N) sgt[id] = nul;
    else { sgt[id].lb = sgt[id].rb = high[who[i]]; }
  }
}


void dfs_first(int u, int p) {
  sub[u] = 1;
  fore(v, adj[u]) if (v != p) {
    high[v] = high[u] + 1;
    par[v] = u;
    dfs_first(v, u);
    sub[u] += sub[v];
  }
}

int cnt;
void dfs_hld(int u, int p, int r) {
  who[++cnt] = u;
  st[u] = cnt;
  head[u] = r;

  int big = -1;
  fore(v, adj[u]) if (v != p) {
    if (big == -1 || sub[v] > sub[big]) {
      big = v;
    }
  }
  if (big != -1) dfs_hld(big, u, r);

  fore(v, adj[u]) if (v != p && v != big)
    dfs_hld(v, u, v);
}

int solve(int u, int v, int c) {
  for(; head[u] != head[v]; v = par[head[v]]) {
    
  }

}

int main() {
  setIO();

  cin >> n >> q;

  foru(i, 1, n) {
    cin >> a[i];
    evts[a[i]].push_back(i);
  }

  foru(i, 2, n) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs_first(1, 0);
  dfs_hld(1, 0, 1);

  foru(i, 1, q) {
    char t;
    cin >> t;
    if (t == 'U') {
      int u, c;
      cin >> u >> c;
      evts[a[u]].push_back(u);
      a[u] = c;
      evts[a[u]].push_back(u);
    }
    else {
      int u, v, c;
      cin >> u >> v >> c;
      // cout << solve(u, v, c) << "\n";
    }
  }
}