#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                swap(a[i], a[j]);
            }
        }
        
        cout << "Buoc " << i + 1 << ": ";
        for (int x : a) {
            cout << x << " ";
        }
        cout << "\n";
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