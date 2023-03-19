#include <bits/stdc++.h>

using namespace std;
int a[10], ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    while (N > 0) {
        a[N%10]++;
        N/=10;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9) continue;
        ans = max(ans, a[i]);
    }
    ans = max(ans, (a[6] + a[9] + 1) / 2);
    cout << ans;
}