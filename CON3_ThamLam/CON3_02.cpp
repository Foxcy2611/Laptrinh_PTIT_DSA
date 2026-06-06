#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll string_to_int(string s, char a, char b){
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == a){
            s[i] = b;
        }
    }

    return stoll(s);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    while(cin >> a >> b){
        ll min_sum = string_to_int(a, '6', '5') + string_to_int(b, '6', '5');
        ll max_sum = string_to_int(a, '5', '6') + string_to_int(b, '5', '6');
        
        cout << min_sum << " " << max_sum << "\n";
    }
    return 0;
}