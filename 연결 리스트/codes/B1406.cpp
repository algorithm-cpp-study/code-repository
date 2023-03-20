#include <bits/stdc++.h>

using namespace std;
typedef long long ll;  //-2^63 ~ 2^63-1
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<int, char> pic;
int INF = 1e9 + 7;
//512MB = 1.2억개 int
//if(nx<0||nx>=n||ny<0||ny>=m) continue;
/*int dz[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={0,0,0,0,1,-1};*/ // 3차원 bfs
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  list<char> L;
  for (auto e : s) L.push_back(e);
  list<char>::iterator cursor = L.end();
  int m;
  cin >> m;
  while (m--) {
    char op;
    cin >> op;
    if (op == 'P') {
      char add;
      cin >> add;
      L.insert(cursor, add);
    }
    else if (op == 'L') {
      if (cursor != L.begin()) cursor--;
    }
    else if (op == 'D') {
      if (cursor != L.end()) cursor++;
    }
    else { // 'B
      if (cursor != L.begin()) {
        cursor--;
        cursor = L.erase(cursor);
      }
    }
  }
  for (auto e : L) cout << e;
  return 0;
}