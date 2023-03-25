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

void parse(string &tmp,deque<int> &dq){ //[1,2,3,4] -> 1 2 3 4 를 deque 에 push_back
    int cur = 0;
    for(int i=1;i+1<tmp.size();i++){
        if(tmp[i]==','){
            dq.push_back(cur);
            cur=0;
        }
        else{
            cur = 10*cur + (tmp[i]-'0');
        }
    }
    //배열에 들어있는 정수는 1과 100 사이
    //==[44]==// 와 같이 원소가 하나일 때 처리
    if(cur!=0)
        dq.push_back(cur);

}
void printList(deque<int> &dq){ //1 2 3 4 -> [1,2,3,4]
    cout << '[';
    for(int i=0;i<dq.size();i++){
        cout << dq[i];
        if(i+1 != dq.size())
            cout << ',';
    }
    cout << "]\n";
}
int t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t; //테스트 케이스의 수
    while(t--){
        deque<int> dq;
        int rev = 0;
        bool isWrong = false;
        string ins;//명령어
        int n;//배열의 수
        string tmp;//배열
        cin >> ins;
        cin >> n;
        cin >> tmp;
        parse(tmp,dq);
        for(auto e:ins){
            if(e=='R'){ //R은 배열을 뒤집는다
                rev = 1-rev; //rev ==1
            }
            else{ //D는 첫 번째 수를 버림
                if(dq.empty()){
                    isWrong = true;
                    break;
                }
                if(!rev) dq.pop_front(); //뒤집히지 않았으면 앞에서 버린다
                else dq.pop_back(); //뒤집혔다면 뒤에서 버린다
            }
        }
        if(isWrong) cout << "error\n";
        else{
            if(rev) reverse(dq.begin(),dq.end());
            printList(dq);
        }
    }


    return 0;
}


