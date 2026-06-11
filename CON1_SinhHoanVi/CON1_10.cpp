#include <iostream>
#include <vector>
#include <string>

using namespace std;

char XOR(char a, char b){
    if(a != b) return '1';
    else return '0';
}

void Solve(){
    string np;
    cin >> np;

    string gray = "";
    gray += np[0];

    for(int i = 1 ; i < np.length(); i++){
        gray.push_back(XOR(np[i], np[i - 1]));
    }

    cout << gray << "\n";
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