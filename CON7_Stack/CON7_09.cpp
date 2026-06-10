#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>

using namespace std;

/*
Duyệt qua chuỗi
+ Nếu gặp ( thì push chỉ số vào stack
+ Nếu gặp ) thì pop ra, ta có 1 cặp ngoặc 
=> Lưu hết vào 1 vector pair

- Sinh các biskmask, giả sử ta có 2 cặp ngoặc ứng vs 4 trường hợp
00 01 10 11 
+ 0: giữ
+ 1: xóa
+ Vì yêu cầu xóa ít nhất 1 cặp nên bỏ qua 00 <=> int i = 1 -> i < (1 << n)
*/

int main() {
    string s;
    cin >> s;
    
    vector<pair<int, int>> brackets;
    stack<int> st;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '('){
            st.push(i);
        } else if(s[i] == ')'){
            brackets.push_back({st.top(), i});
            st.pop();
        }
    }

    int n = brackets.size();
    set<string> res; // Dung de auto sap xep va xoa chuoi trung lap

    // Chay den 2^n - 1
    for(int mask = 1 ; mask < (1 << n) ; mask++){
        vector<bool> remove_char(s.length(), false);

        for(int i = 0 ; i < n ; i++){
            // Xem bit thu i cua mask co bat ?
            if(mask & (1 << i)){
                remove_char[brackets[i].first] = true;
                remove_char[brackets[i].second] = true;

                string tmp = "";
                for(int i = 0 ; i < s.length() ; i++){
                    if(! remove_char[i]){
                        tmp += s[i];
                    }
                }
                res.insert(tmp);
            }
        }
    }

    for(auto it : res){
        cout << it << "\n";
    }
}