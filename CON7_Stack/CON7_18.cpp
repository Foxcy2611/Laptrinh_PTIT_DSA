#include <iostream>
#include <stack>
#include <string>

using namespace std;
#define ll long long

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; 
}

ll applyOp(ll a, ll b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : 0; // Thêm check chia 0 cho an toàn
    }
    return 0;
}

void solve() {
    string s;
    getline(cin, s); // ĐỌC NGUYÊN DÒNG, KHÔNG DÙNG cin >> s
    
    stack<ll> values; 
    stack<char> ops;  

    for (int i = 0; i < s.length(); i++) {
        
        // Nhảy qua khoảng trắng
        if (s[i] == ' ') continue;

        if (s[i] == '(') {
            ops.push(s[i]);
        } 
        else if (isdigit(s[i])) {
            ll val = 0;
            while (i < s.length() && isdigit(s[i])) {
                val = (val * 10) + (s[i] - '0');
                i++;
            }
            values.push(val);
            i--; // Trừ đi 1 đvi, while ++ thừa
        } 
        else if (s[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                // Phòng thủ RTE khi stack không đủ số
                if (values.size() < 2) break; 
                ll val2 = values.top(); values.pop();
                ll val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            if (!ops.empty() && ops.top() == '(') ops.pop(); 
        } 
        // Bắt đích danh toán tử để tránh các ký tự rác
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(s[i])) {
                if (values.size() < 2) break;
                ll val2 = values.top(); values.pop();
                ll val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(s[i]);
        }
    }

    while (!ops.empty()) {
        if (values.size() < 2) break;
        ll val2 = values.top(); values.pop();
        ll val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    if (!values.empty()) {
        cout << values.top() << "\n";
    } else {
        cout << 0 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        cin.ignore(); // DỌN BỘ ĐỆM TRƯỚC KHI GỌI GETLINE
        while (t--) {
            solve();
        }
    }
    return 0;
}