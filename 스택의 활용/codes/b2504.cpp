#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s;

    int tmp = 1, ans = 0;
    bool err = false;
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            st.push(s[i]);
            tmp *= 2;
        } else if(s[i] == '['){
            st.push(s[i]);
            tmp *= 3;
        } else if(s[i] == ')'){
            if(st.empty()){
                err = true;
                break;
            } else if(st.top() == '('){
                if(s[i-1] == '(') ans += tmp;
                st.pop();
                tmp /= 2;
            } else {
                err = true;
                break;
            }
        } else if (s[i] == ']') {
            if(st.empty()){
                err = true;
                break;
            } else if (st.top() == '[') {
                if(s[i-1] == '[') ans += tmp;
                st.pop();
                tmp /= 3;
            } else {
                err = true;
                break;
            }
        }
    }
    if(err == true || !st.empty()) cout << 0 << '\n';
    else cout << ans << '\n';
}