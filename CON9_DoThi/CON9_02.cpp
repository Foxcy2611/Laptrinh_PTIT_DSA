#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void Solve(){
    int n;
    cin >> n;
    cin.ignore();

    vector<int> dsk[n + 1];
    vector<pair<int, int>> dsc;

    for(int i = 1 ; i <= n ; i++){
        string line;
        getline(cin, line);

        stringstream ss(line);
        int res;

        while(ss >> res){
            dsk[i].push_back(res);
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int x : dsk[i]){
            if(i < x){
                dsc.push_back({i, x});
            }
        }
    }
    for(auto it : dsc){
        cout << it.first << " " << it.second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solve();
}