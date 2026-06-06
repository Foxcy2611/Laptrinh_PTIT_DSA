#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool Check(string s){
    stack<char> st;

    for(char c : s){
        if(c == '[' || c == '{' || c == '('){
            st.push(c);
        } else if(c == ']' || c == '}' || c == ')') {
            if(st.empty()){
                return false;
            } else {
                char p = st.top();
                st.pop();

                if(c == ']' && p != '['){
                    return false;
                } else if(c == ')' && p != '('){
                    return false;
                } else if(c == '}' && p != '{'){
                    return false;
                }
            }
        }
    }

    return st.empty();
}

void Solve(){
    string s;
    getline(cin, s);

    // Kỹ thuật gỡ mìn: Cắt bỏ đuôi \r (nếu có) do khác biệt hệ điều hành Windows - Linux
    if (!s.empty() && s.back() == '\r') {
        s.pop_back();
    }

    if(Check(s)){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if(cin >> t){
        // Xóa sạch bộ đệm tới tận phím Enter, thay vì chỉ bỏ qua 1 ký tự
        cin.ignore(10000, '\n');

        while(t--){
            Solve();
        }
    }

    return 0;
}