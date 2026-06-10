#include <bits/stdc++.h>

using namespace std;

/*
st: lưu dấu 1 cho +, -1 cho -
biến curr_sign lưu dấu thực sự biến chuẩn bị đc xét
dấu +, dấu biến sẽ là 1 * ...
dấu -, dấu biến sẽ là -1 * ...
gặp ( ta đẩy dấu trc đó (curr_sign) vào stack
*/

string SS_Chuoi(string s){
    string res = "";
    stack<int> st;
    st.push(1); // Mac dinh dau ngoai cung la '+'

    int curr_sign = 1;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == ' ') continue;

        // Cap nhat curr_sign dua vao toan tu va dau bao trum
        if(s[i] == '+'){
            curr_sign = 1 * st.top();
        } else if(s[i] == '-'){
            curr_sign = -1 * st.top();
        }
        // Khi mo ngoac '(', luu lai context dau hien tai vao stack
        else if(s[i] == '('){
            st.push(curr_sign);
            curr_sign = 1 * st.top();
        }
        // Khi dong ngoac, rut context ra
        else if(s[i] == ')'){
            st.pop();
        }
        // Neu la bien (A - Z hoac a - z)
        else if(isalpha(s[i])){
            if(curr_sign == 1 && res.length() > 0) res += '+';
            if(curr_sign == -1) res += '-';

            while(i < s.length() && isalpha(s[i])){
                res += s[i];
                i++;
            }
            i--; // Lui lai 1 buoc vi while + thua
            curr_sign = 1 * st.top();
        }
    }
    return res;
}

void Solve(){
    string a;
    cin >> a;

    cout << SS_Chuoi(a) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            Solve();
        }
    }
    return 0;
}