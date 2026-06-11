#include <bits/stdc++.h>

using namespace std;

// 1. Tim vi tri i (bat dau i = n - 2) va tim
// a[i] < a[i + 1], neu ko t/m thi day giam dan -> IN tu 1 -> n
// 2. Tim ptu the cho, duyet tu cuoi mang j = n - 1, tim ptu 1st a[j] > a[i]
// 3. swap
// 4. reverse tu a[i+1] den cuoi mang

void Solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    // 1.
    int i = n - 2;
    while(i >= 0 && a[i] >= a[i + 1]){
        i--;
    }
    // Neu day giam dan, thi in ra
    if(i < 0){
        for(int j = 1 ; j <= n ; j++){
            cout << j << " ";
        }
        cout << "\n";
        return;
    }

    // 2. 
    int j = n - 1;
    while(a[j] <= a[i]){
        j--;
    }

    // 3.
    swap(a[i], a[j]);

    // 4.
    int l = i + 1, r = n - 1;
    while(l < r){
        swap(a[l], a[r]);
        l++;
        r--;
    }
    for(int x : a){
        cout << x << " ";
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