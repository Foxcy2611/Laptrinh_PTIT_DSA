#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
const int MAX_VAL = 300; 

// p la snt ; x1, x2, ..., xi >= p ; i = n ; sigma(i=1; n)x = s

int n, p, s; 
vector<int> prime(MAX_VAL, 1);
vector<vector<int>> res;
vector<int> curr;

void Sang_Prime(){
    prime[0] = 0;
    prime[1] = 0;

    for(int i = 2 ; i * i < MAX_VAL ; i++){
        if(prime[i]){
            for(int j = i * i ; j < MAX_VAL ; j += i){ 
                prime[j] = 0;
            }
        }
    }
}

void Try(int idx, int curr_sum){
    if(curr.size() == n){
        if(curr_sum == s){
            res.push_back(curr);
        }
        return;
    }

    for(int i = idx ; i < prime.size() ; i++){
        if(prime[i]){
            if(curr_sum + i > s) break;

            curr.push_back(i);

            Try(i + 1, curr_sum + i);

            curr.pop_back();
        }
    }
}

void Solve(){
    cin >> n >> p >> s;
    
    res.clear();
    curr.clear();

    Try(p + 1, 0);

    cout << res.size() << "\n";
    for (auto comb : res) {
        for (int i = 0; i < comb.size(); i++) {
            cout << comb[i] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Sang_Prime();

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
}