#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;


struct Matrix {
    ll mat[15][15];
    int n;
};

Matrix Multi_Matrix(Matrix A, Matrix B){
    Matrix C;
    C.n = A.n;

    for(int i = 0 ; i < C.n ; i++){
        for(int j = 0 ; j < C.n ; j++){
            C.mat[i][j] = 0;
            for(int k = 0 ; k < C.n  ; k++){
                C.mat[i][j] = (C.mat[i][j] + A.mat[i][k] * B.mat[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix Binpow(Matrix A, ll k){
    Matrix res;
    res.n = A.n;
    for(int i = 0 ; i < res.n ; i++){
        for(int j = 0 ; j < res.n ; j++){
            if(i == j) res.mat[i][j] = 1;
            else res.mat[i][j] = 0;
        }
    }

    while(k > 0){
        if(k % 2 == 1) res = Multi_Matrix(res, A);

        A = Multi_Matrix(A, A);

        k /= 2;
    }

    return res;
}

void Solve(){
    int n, k;
    cin >> n >> k;

    Matrix A;
    A.n = n;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> A.mat[i][j];
        }
    }

    Matrix Result;
    Result = Binpow(A, k);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << Result.mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
}