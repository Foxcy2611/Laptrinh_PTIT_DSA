#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

void Solve(){
    string s;
    cin >> s;
    stack<ll> st;
    for(int i = s.length() - 1 ; i >= 0 ; i--){
        if(isdigit(s[i])){
            st.push(s[i] - '0');
        } else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            if(st.size() < 2) continue;

            ll op1 = st.top(); 
            st.pop();
            ll op2 = st.top();
            st.pop();

            ll tmp = 0;
            if(s[i] == '+') tmp = op1 + op2;
            else if(s[i] == '-') tmp = op1 - op2;
            else if(s[i] == '*') tmp = op1 * op2;
            else if(s[i] == '/'){
                if(op2 != 0) tmp = op1 / op2;
                else tmp = 0;
            }
            st.push(tmp);
        }
    }
    if(! st.empty()){
        cout << st.top() << "\n";
    } else {
        cout << 0 << "\n";
    }
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