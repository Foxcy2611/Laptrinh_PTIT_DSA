#include <bits/stdc++.h>

/*
    Cho mảng A gồm n ptu
    Tìm dãy con liên tục A[l] -> A[r] sao cho
    Khi sắp xếp lại A[l->r] thì thu đc A là mảng tăng dần

    2
    11
    10 12 20 30 25 40 32 31 35 50 60
    9
    0 1 15 25 6 7 30 40 50

    4 9
    3 6

    ////////////
    - Đi từ trái sang phải
    + Đúng quy luật thì cái sau lớn hơn cái trước
    + Ta lưu số lớn nhất từng gặp, nếu gặp số nhỏ hơn
    => Chứng tỏ sai vị trí, đáng dấu R
    - Ngược lại vs L
*/

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void Solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int &x : a)
        cin >> x;

    int l = 0, r = n - 1;

    int curr_max = a[0];
    for(int i = 0 ; i < n ; i++){
        if(curr_max > a[i]){
            r = i;
        } else {
            curr_max = a[i];
        }
    }

    int curr_min = a[n - 1];
    for(int i = n - 1 ; i >= 0 ; i--){
        if(curr_min < a[i]){
            l = i;
        } else {
            curr_min = a[i];
        }
    }
    cout << l + 1 << " " << r + 1 << "\n";
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