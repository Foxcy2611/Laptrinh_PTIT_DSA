#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

bool CheckStr(string s){
    stack<char> st;
    
    for(char c : s){
        if(c == ' ') continue;

        if(c != ')'){
            st.push(c);
        } else {
            bool isCheck = false;
            
            while(!st.empty() && st.top() != '('){
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isCheck = true; 
                }
                st.pop();
            }

            if(!st.empty()){
                st.pop(); 
            }

            if(isCheck == false) return true; 
        }

    }
    return false;   
}

void Solve(){
    string s;
    getline(cin, s);

    if (!s.empty() && s.back() == '\r') s.pop_back();

    if (CheckStr(s)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        cin.ignore(); 
        while(t--){
            Solve();
        }
    }
    return 0;
}