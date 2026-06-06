#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

/*
    - Moi hang chi dat dc 1 quan hau
    - Tai hang i, khi muốn đặt quan hau ở cột j, cần check tại ô i, j
    + Cột j có trống k
    + Đường chéo xuôi \ có ai chưa
    + Đường chéo ngược / có ai chưa
*/

int A[9][9];
bool cot[20], cheo1[20], cheo2[20];
int max_score;

void Try(int i, int current_score) {
    if (i > 8) {
        max_score = max(max_score, current_score); 
        return;
    }

    for (int j = 1; j <= 8; j++) {
        if (!cot[j] && !cheo1[i - j + 8] && !cheo2[i + j]) {
            
            cot[j] = true;
            cheo1[i - j + 8] = true;
            cheo2[i + j] = true;

            Try(i + 1, current_score + A[i][j]);

            cot[j] = false;
            cheo1[i - j + 8] = false;
            cheo2[i + j] = false;
        }
    }
}

void Solve() {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cin >> A[i][j];
        }
    }

    max_score = 0;
    memset(cot, false, sizeof(cot));
    memset(cheo1, false, sizeof(cheo1));
    memset(cheo2, false, sizeof(cheo2));

    Try(1, 0);

    cout << max_score << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            Solve();
        }
    }
    
    return 0;
}