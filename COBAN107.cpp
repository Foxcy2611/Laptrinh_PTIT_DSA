#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MOD = 1e9 + 7;
int n;
ll k;

struct Matran {
    ll c[15][15];
    
    Matran(){
        for(int i = 0 ; i < 15 ; i++){
            for(int j = 0 ; j < 15 ; j++){
                c[i][j] = 0;
            }
        }
    }
};

Matran Nhan_Matran(Matran a, Matran b){
    Matran res;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            res.c[i][j] = 0;
            for(int l = 0 ; l < n ; l++){
                res.c[i][j] = (res.c[i][j] + a.c[i][l] * b.c[l][j]) % MOD;
            }
        }
    }
    return res;
}

Matran Luy_thua(Matran a, ll k){
    Matran res;

    for(int i = 0 ; i < n ; i++){
        res.c[i][i] = 1;
    }

    while(k > 0){
        if(k % 2 == 1){
            res = Nhan_Matran(res, a);
        }
        a = Nhan_Matran(a, a);
        k /= 2;
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        Matran A;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> A.c[i][j];
            }
        }

        Matran X = Luy_thua(A, k);

        ll sum = 0;

        for(int i = 0 ; i < n ; i++){
            sum += X.c[i][i];
        }
        cout << sum % MOD << endl;
    }
}