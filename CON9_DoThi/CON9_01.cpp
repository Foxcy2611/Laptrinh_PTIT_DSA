#include <bits/stdc++.h>

using namespace std;

// Đáp án chuẩn, đề bài sai
int main(){
    int n, x;
    cin >> n;
    vector<vector<int>> a(n+1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
        cin >> x;
        if(x == 1){
            a[i].push_back(j);
        	} 
        }
    }
    for(int i = 1; i <= n; i++){
        cout << i << ": ";
        for(auto j : a[i])
            cout << j << " ";
        cout << endl;
    }
    return 0;
}