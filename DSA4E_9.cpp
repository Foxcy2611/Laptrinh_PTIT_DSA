#include <bits/stdc++.h>

using namespace std;

void Dquy(const string &s, int idx = 0){
    if(idx == s.size()) return;
    
    Dquy(s, idx + 1);

    cout << s[idx];

}

int main(){
    int t;
    cin >> t;
    while(t--){
        scanf("\n");
        string s;
        getline(cin, s);
        Dquy(s);
        cout << endl;
    }
}