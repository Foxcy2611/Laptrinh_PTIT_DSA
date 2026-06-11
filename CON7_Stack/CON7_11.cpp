#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

/*
- Dùng stack giam giữ các toán tử
1. Nếu là toán hạng, cho ra chuỗi kết quả
2. Nếu là (: Đẩy vào stack
3. Nếu là ): Rút liên tục các toán tử đầu stack ghép vào res cho đến khi gặp (
4. Nếu là toán tử (+-*,chia, ^), Xét độ ưu tiên vs toán tử đầu stack
Nếu đỉnh stack có độ ưu tiên >= c, rút stack cho res
*/

int precedence(char c){
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0; // ()
}

void Solve(){
    string s;
    cin >> s;

    string res = "";
    stack<char> st;

    for(int i = 0 ; i < s.length() ; i++){
        char c = s[i];

        if(isalpha(c) || isdigit(c)){
            res += c;
        } else if(c == '('){
            st.push(c);
        } else if(c == ')'){
            while(! st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        } else {
            while(! st.empty() && precedence(st.top()) >= precedence(c)){
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(! st.empty()){
        if(st.top() != '('){
            res += st.top();
        }
        st.pop();
    }

    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
}