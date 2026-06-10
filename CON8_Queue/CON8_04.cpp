#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <map>

using namespace std;

/*
- Ý tưởng, ta luôn lấy các phần tử có số lần
xuất hiện lớn nhất lần lượt trừ đi 1 lần
cho đến khi đủ K lần
- Sử dụng priority_queue
*/

long long pow(int a){
    return a * a;
}

void Solve(){
    int k;
    cin >> k;
    string s;
    cin >> s;

    priority_queue<int> q;
    map<char, int> mp;

    for(int i = 0 ; i < s.length() ; i++){
        mp[s[i]]++;
    }

    for(auto it : mp){
        q.push(it.second);
    }

    while(k--){
        int top = q.top();
        q.pop();
        top--;
        q.push(top);
    }
    long long sum = 0;
    while(! q.empty()){
        sum += pow(q.top());
        q.pop();
    }
    cout << sum << "\n";
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