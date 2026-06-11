#include <bits/stdc++.h>

using namespace std;

#define ll long long

void Solve(){
    string s;
    cin >> s;
    stack<string> st;

    for(int i = 0 ; i < s.length() ; i++){
        if(isalpha(s[i])){
            st.push(string(1, s[i]));
        } else {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string tmp;
            tmp = "(" + op2 + s[i] + op1 + ")";
            st.push(tmp);
        }
    }
    cout << st.top() << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        Solve();
    }

}