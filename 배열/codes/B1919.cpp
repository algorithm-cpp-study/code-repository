#include <bits/stdc++.h>

using namespace std;
int a[2][26], res;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    for (auto i : s1) a[0][i-'a']++;
    for (auto i : s2) a[1][i-'a']++;
    for (int i = 0; i < 26; i++) res += abs(a[0][i] - a[1][i]);
    cout << res;
    return 0;
}