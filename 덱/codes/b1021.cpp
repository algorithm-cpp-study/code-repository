#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    deque<int> dq;
    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++) dq.push_back(i);

    int ans = 0;
    for(int i=0; i<m; i++){
        int x; cin >> x;
        int idx = find(dq.begin(), dq.end(), x) - dq.begin();       //find가 iterator를 반환하기 때문에 dq.begin()을 빼줘야 인덱스 값이 나온다
        while(x != dq.front()){
            if(idx < dq.size() - idx){
                dq.push_back(dq.front());
                dq.pop_front();
            }else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            ans++;
        }
        if(x == dq.front()){
            dq.pop_front();
        }
    }
    cout << ans << '\n';
}