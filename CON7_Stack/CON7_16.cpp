#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

/*
- Nếu gặp toán tử, lôi 2 thằng trong stack ra
=> Tính toán rồi push lại
- Duyệt từ trái qua phải
*/

void Solve(){
    string s;
    cin >> s;
    stack<ll> st;
    for(int i = 0 ; i < s.length() ; i++){
        if(isdigit(s[i])){
            st.push(s[i] - '0');
        } else {
            ll op1 = st.top(); 
            st.pop();
            ll op2 = st.top();
            st.pop();

            ll tmp = 0;
            if(s[i] == '+') tmp = op1 + op2;
            else if(s[i] == '-') tmp = op2 - op1;
            else if(s[i] == '*') tmp = op1 * op2;
            else if(s[i] == '/') tmp = op2 / op1;

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