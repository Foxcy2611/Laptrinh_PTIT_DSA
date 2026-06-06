#include <iostream>
#include <vector>

using namespace std;

/*
- Tại mỗi bước, rút ra 1 con số
+ Tiến hành so sánh vs các con số trc đó
+ Dịch các con số lớn hơn nó sang phải 1 đơn vị
+ Đặt nó đúng vị trí
*/

void Solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<vector<int>> b(n);
    for(int &x : a){
        cin >> x;
    }

    for(int i = 0 ; i < n ; i++){
        int key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] >= key){
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
        for(int k = 0 ; k <= i; k++){
            b[i].push_back(a[k]);
        }
    }
    
    for(int k = n - 1 ; k >= 0 ; k--){
        cout << "Buoc " << k << ": ";
        for(int x : b[k]){
            cout << x << " ";
        }
        cout << "\n";
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