#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000000;
vector<bool> isPrime(MAXN + 1, true); 

void Sieve() {
    isPrime[0] = isPrime[1] = false; 
    
    for (int p = 2; p * p <= MAXN; p++) {
        if (isPrime[p] == true) {
            for (int i = p * p; i <= MAXN; i += p) {
                isPrime[i] = false;
            }
        }
    }
}

void Solve() {
    int n;
    cin >> n;
    
    for (int i = 2; i <= n / 2; i++) {
        if (isPrime[i] && isPrime[n - i]) {
            cout << i << " " << n - i << "\n";
            return; 
        }
    }
    
    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Sieve(); 
    
    int t;
    if (cin >> t) {
        while (t--) {
            Solve();
        }
    }
    
    return 0;
}