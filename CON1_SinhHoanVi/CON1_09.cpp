#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* Voi n
1. Push 0, 1 vao vector
2. Soi guong, ta push them cac gia tri
Vdu: 0 1 => 1 0 => 0 1 1 0  ; 00 01 11 10 => 10 11 01 00
3. Them 0 vao phan that, them 1 vao phan guong => Them o dau
0 1 -> 00 01
1 0 -> 11 10
*/

void Solve(){
    int n;
    cin >> n;
    
    // 1.
    vector<string> gray;
    gray.push_back("0");
    gray.push_back("1");

    for(int i = 2 ; i <= n ; i++){
        int curr_len = gray.size();
        // 2. Nhan ban
        for(int j = curr_len - 1; j >= 0 ; j--){
            gray.push_back(gray[j]);
        }

        // Them 0 vao phan 1
        for(int j = 0 ; j < curr_len ; j++){
            gray[j] = "0" + gray[j];
        }
        // Them 1 vao phan 2
        for(int j = curr_len ; j < 2 * curr_len ; j++){
            gray[j] = "1" + gray[j];
        }
    }
    for(string s : gray){
        cout << s << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        Solve();
    }
    return 0;
}