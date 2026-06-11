#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

/*
- Dùng stack lưu chuỗi ký tự và thực hiện ghép chuỗi
1. Duyệt phải qua
2. Gặp toán hạng, đẩy nó vào stack
3. Nếu gặp toán tử
+ Lấy chuỗi ở đỉnh stack ra làm toán hạng bên phải (op1)
+ Lấy chuỗi tiếp theo làm toán tử trái (op2)
+ Ghép lại: ( op2 toan_tu op1 )
+ Đẩy ngược lại stack
4. Thu đc chuỗi oke
*/

void Solve(){
    string s;
    cin >> s;

    stack<string> st;

    for(int i = s.length() - 1 ; i >= 0 ; i--){
        char c = s[i];
        if(isalpha(c)){
            st.push(string(1, c));
        } else {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string tmp = op1 + op2 + c;
            st.push(tmp);
        }
    }
    cout << st.top() << "\n";
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