#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        int arr[26] = {};
        string s1, s2;
        cin >> s1 >> s2;
        for(auto a : s1) arr[a - 'a']++;
        for(auto a : s2) arr[a - 'a']--;

        bool ans = true;
        for(int j=0; j<26; j++){
            if(arr[j] > 0 || arr[j] < 0) ans = false;
        }
        if(ans) cout << "Possible" << "\n";
        else cout << "Impossible" << "\n";
    }
}