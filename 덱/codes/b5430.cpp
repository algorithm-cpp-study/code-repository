#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;
    while(T--){
        string p; cin >> p;
        int size; cin >> size;
        string nums; cin >> nums;

        deque<int> dq;
        int tmp=0;
        //입력
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == '[') continue;
            if(nums[i] >= '0' && nums[i] <= '9') tmp = (tmp*10) + (nums[i] - '0');
            if(nums[i] == ',' || nums[i] == ']'){
                if(tmp != 0){
                    dq.push_back(tmp);
                    tmp = 0;
                }
            }
        }
        //RD 로직
        bool err = false;
        int rev = 1;
        for(auto c : p){
            if(c == 'R') {
                rev *= -1;
            }
            else{
                if(dq.empty()) {
                    err = true;
                    break;
                }
                if(rev < 0){
                    dq.pop_back();
                }else{
                    dq.pop_front();
                }
            }
        }
        //출력
        if(err){
            cout << "error" << '\n';
        }else{
            cout << '[';
            while(!dq.empty()){
                if(rev > 0){
                    cout << dq.front();
                    dq.pop_front();
                    if(dq.empty()) break;
                    cout << ',';
                }else {
                    cout << dq.back();
                    dq.pop_back();
                    if(dq.empty()) break;
                    cout << ',';
                }
            }
            cout << ']' << '\n';
        }
    }
}