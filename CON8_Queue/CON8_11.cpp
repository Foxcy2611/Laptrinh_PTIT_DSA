#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

/*
- Sàng + thay đổi từng chữ số và check xem số này đã đc thay chưa
*/

bool isPrime[10005];

void Sang(){
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    for(int i = 2 ; i * i < 10000 ; i++){
        if(isPrime[i]){
            for(int j = i * i ; j < 10000 ; j += i){
                isPrime[j] = false;
            }
        }
    }
}

void Solve(){
    int s, t;
    cin >> s >> t;
    vector<int> dist(10005, -1);
    queue<int> q;

    q.push(s);
    dist[s] = 0;
    
    while(! q.empty()){
        int val = q.front();
        q.pop();

        if(val == t){
            cout << dist[val] << "\n";
            return;
        }

        string str_val = to_string(val);
        for(int i = 0 ; i < 4 ; i++){
            // Luu lai so ban dau
            char char_str = str_val[i];
            for(char c = '0' ; c <= '9' ; c++){
                if(c == '0' && i == 0) continue;

                str_val[i] = c;
                int next_val = stoi(str_val);
                
                // La 1 snt va chua dc tham (visited)
                if(isPrime[next_val] && dist[next_val] == -1){
                    dist[next_val] = dist[val] + 1;
                    q.push(next_val);
                }
            }
            str_val[i] = char_str;
        }
    }
    cout << "-1\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Sang();

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
}