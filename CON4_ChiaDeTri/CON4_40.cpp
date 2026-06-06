#include <bits/stdc++.h>

using namespace std;

int Search(vector<int>& nums, int n){
    int l = 0 ;
    int r = n - 1;
    int ans = n;

    while(l <= r){
        int m = l + (r - l) / 2;

        if(nums[m] == 1){
            ans = m;
            r = m - 1;
        } else if(nums[m] == 0){
            l = m + 1;
        }
    }

    return ans;
}

void Solve(){
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int &x : nums){
        cin >> x;
    }

    cout << Search(nums, n) << endl;
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