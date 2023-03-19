#include <bits/stdc++.h>

using namespace std;

int n, res[10], ans=0;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    while(n != 0) {
        res[n % 10]++;
        n /= 10;
    }

    for(int i=0; i<10; i++) {
        if(i==6 || i==9) continue;
        ans = max(ans, res[i]);
    }
    ans = max(ans, (res[6] + res[9] + 1) / 2);
    cout << ans;
}