#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min_sum = 2e9;
    int min_diff = 2e9; 

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = a[i] + a[j];
            
            if (abs(sum) < min_diff) {
                min_diff = abs(sum);
                min_sum = sum;
            }
        }
    }

    cout << min_sum << "\n";
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