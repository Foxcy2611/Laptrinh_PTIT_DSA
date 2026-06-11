#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool Check(string s){
    stack<char> st;

    for(char c : s){
        if(c == '[' || c == '(' || c == '{'){
            st.push(c);
        } else if(c == ']' || c == ')' || c == '}'){
            if(st.empty()) return false;
            char p = st.top();
            st.pop();
            if(c == ']' && p != '[') return false;
            else if(c == ')' && p != '(') return false;
            else if(c == '}' && p != '{') return false;
        }
    }
    return st.empty();
}

void Solve(){
    string s;
    getline(cin , s);
    
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
    if (cin >> t) {
        cin.ignore(); // ĐẶT Ở ĐÂY: Chỉ chạy 1 lần để xóa Enter sau khi nhập T
        
        while(t--){
            Solve(); // Trong này không được ignore thêm gì nữa cả
        }
    }

    return 0;
}