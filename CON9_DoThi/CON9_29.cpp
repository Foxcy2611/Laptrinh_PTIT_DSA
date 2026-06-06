// Chu trình Euler (In ra 2): Khi TẤT CẢ các đỉnh trong đồ thị đều có bậc chẵn (số đỉnh bậc lẻ = 0).

// Đường đi Euler (In ra 1): Khi có CHÍNH XÁC 2 đỉnh có bậc lẻ. (Đường đi sẽ xuất phát ở một đỉnh bậc lẻ và kết thúc ở đỉnh bậc lẻ còn lại).

// Không có gì (In ra 0): Các trường hợp còn lại.

#include <iostream>
#include <cstring>

using namespace std;

int degree[1005];

void Solve(){
    int n, m;
    cin >> n >> m;
    memset(degree, 0, sizeof(degree));

    for(int i = 1 ; i <= m ; i++){
        int x, y;
        cin >> x >> y;

        degree[x]++;
        degree[y]++;
    }

    int bac = 0;
    for(int i = 1 ; i <= n ; i++){
        if(degree[i] % 2 != 0){
            bac++;
        }
    }
    switch(bac){
        case 0:
            cout << "2\n";
            break;
        case 2:
            cout << "1\n";
            break;
        default:
            cout << "0\n";
            break;   
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    
    return 0;
}