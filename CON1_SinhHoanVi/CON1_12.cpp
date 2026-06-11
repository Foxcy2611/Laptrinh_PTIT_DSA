#include <iostream>

using namespace std;

int n, k;
int a[25];

// i: Vi tri dang xet
// cnt1: So luong bit 1

void Try(int i, int cnt1){
    if(cnt1 > k) return;

    for(int j = 0 ; j <= 1 ; j++){
        // Thu dien 0 trc, 1 sau
        a[i] = j;

        // Cap nhat cnt1
        int next_cnt1 = cnt1 + (j == 1 ? 1 : 0);

        // Neu den vi tri cuoi cung
        if(i == n){
            if(next_cnt1 == k){
                for(int x = 1 ; x <= n ; x++){
                    cout << a[x] ;
                }
                cout << "\n";
            } 
        } else {
            Try(i + 1, next_cnt1);
        }
    }
}

void Solve(){
    cin >> n >> k;
    // Bat dau vi tri 0, bit 1 la so 0
    Try(1, 0);
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