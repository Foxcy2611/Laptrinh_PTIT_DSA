#include <iostream>
#include <vector>

using namespace std;

// Cthuc chạm trần của vị trí i (i = 1 -> ..)
//  N - K + 1
// 1. Dò từ phải -> trái, tìm ptu chưa chạm trần
// 2. Tăng phần tử đó lên 1 (ans)
// 3. Những ptu đứng sau ans sẽ = ans + 1

void Solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(k + 1);
    for(int x = 1 ; x <= k ; x++){
        cin >> a[x];
    }

    int j = 0;
    for(int i = k ; i >= 1 ; i--){
        if(a[i] < n - k + i){
            a[i] = a[i] + 1;
            j = i;
            break;
        }
    }
    if(j == 0){
        for(int i = 1; i <= k; i++) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = j + 1 ; i <= k ; i++){
        a[i] = a[i - 1] + 1;
    }

    for(int x = 1 ; x <= k ; x++){
        cout << a[x] << " ";
    }
    cout << "\n";
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