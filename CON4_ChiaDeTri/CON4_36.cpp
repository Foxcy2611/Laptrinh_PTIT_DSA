#include <bits/stdc++.h>

using namespace std;

long long binToDec(const string &s) {
    long long res = 0;
    for(char c : s) {
        res = res * 2 + (c - '0');
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        scanf("\n");
        string a, b;
        cin >> a >> b;
        
        long long c = binToDec(a);
        long long d = binToDec(b);
        cout << c * d << endl;
    }
}

