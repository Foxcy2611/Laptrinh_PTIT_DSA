#include <iostream>
#include <vector>

using namespace std;

#define ll long long

/*
Nghịch thế: i < j và a[i] > a[j]

Merge sort là quy trình chia đổi mảng, sắp xếp 2 phần rồi ghép
=> Biến đổi thuật toán

- Việc với i thuộc mảng trái, j mảng phải
+ Các mảng đều được sắp xếp tăng dần
+ Nếu a[i] > a[j] 
=> Mọi phần tử mảng trái sau i đều lớn hơn thằng j đó

=> Số cặp += (số lượng phần tử mảng trái - i), rồi cho i++
*/

ll merge_and_count(vector<int>& a, int l, int m, int r) {
    vector<int> temp;
    int i = l;        
    int j = m + 1;    
    ll inv_count = 0; 

    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {

            temp.push_back(a[j]);
            inv_count += (m - i + 1); 
            j++;
        }
    }

    while (i <= m) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);

    for (int k = l; k <= r; k++) {
        a[k] = temp[k - l];
    }

    return inv_count;
}

ll merge_sort(vector<int>& a, int l, int r) {
    ll inv_count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        
        inv_count += merge_sort(a, l, m);
        
        inv_count += merge_sort(a, m + 1, r);
        
        inv_count += merge_and_count(a, l, m, r);
    }
    return inv_count;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << merge_sort(a, 0, n - 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}