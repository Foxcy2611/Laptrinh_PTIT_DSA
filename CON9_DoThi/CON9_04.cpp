#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void Solve(){
    int n;
    cin >> n;
    cin.ignore();
    
    vector<vector<int>> mtr(n + 1, vector<int>(n + 1, 0));

    for(int i = 1 ; i <= n ; i++){
        string line;
        getline(cin, line);

        stringstream ss(line);
        int v;
        while(ss >> v){
            mtr[i][v] = 1;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cout << mtr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solve();
}