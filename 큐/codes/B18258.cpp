#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

int N, h, t, q[2000002];
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    while(N--) {
        string com;
        cin >> com;
        if (com == "push") {
            int x;
            cin >> x;
            q[t++] = x;
        } else if (com == "pop") {
            cout << (h == t ? -1 : q[h++]) << '\n';
        } else if (com == "size") {
            cout << t-h << '\n';
        } else if (com == "empty") {
            cout << (t==h) << '\n';
        } else if (com == "front") {
            cout << (h == t ? -1 : q[h]) << '\n';
        } else if (com == "back") {
            cout << (h == t ? -1 : q[t-1]) << '\n';
        }
    }

}