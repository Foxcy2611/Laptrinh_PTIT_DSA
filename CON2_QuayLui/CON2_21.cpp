#include <bits/stdc++.h>
using namespace std;

string s;
bool used[15];

void Try(string curr){
    if(curr.length() == s.length()){
        cout << curr << " ";
        return;
    }
    for(int i = 0 ; i < s.length() ; i++){
        if(!used[i]){
            used[i] = true;
            Try(curr + s[i]);
            used[i] = false;
        }
    }
}

void Solve(){
    cin >> s;
    memset(used, false, sizeof(used));

    Try("");
    cout << "\n";
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
}