#include <iostream>

using namespace std;

int parent[1005];

void make_set(int v) {
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }
}

int find_set(int u) {
    if (u == parent[u]) {
        return u;
    }
    return parent[u] = find_set(parent[u]);
}

bool union_sets(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);

    if (root_u == root_v) {
        return true;
    }

    parent[root_v] = root_u;
    return false;
}

void Solve() {
    int v, e;
    cin >> v >> e;

    make_set(v);

    bool has_cycle = false;
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        
        if (!has_cycle) {
            if (union_sets(x, y)) {
                has_cycle = true;
            }
        }
    }

    if (has_cycle) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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