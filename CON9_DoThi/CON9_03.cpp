#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void Solve(){
    int n;
    cin >> n;
    
    vector<int> adj[1005];

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            int val;
            cin >> val;
            
            if(val){
                adj[i].push_back(j);
            }
        }
    }    

    for(int i = 1 ; i <= n ; i++){
        for(int x : adj[i]){
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solve();
}