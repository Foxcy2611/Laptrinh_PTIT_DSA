#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, k;
vector<string> results;
string curr_str = "";

// Dieu kien giu nguyen 100% logic cua ban
// 1. Khong dc co (k + 1) chu A
// 2. Xau phai co dung k chu A
// 3. Khong dc ton tai k chu A thu 2
bool check(string s){
    string over_k = string(k + 1, 'A');
    if(s.find(over_k) != string::npos) return false;

    string exact_k = string(k, 'A');
    int pos1 = s.find(exact_k);
    if(pos1 == string::npos) return false;

    int pos2 = s.find(exact_k, pos1 + 1);
    return pos2 == string::npos;
}

void Try(int i){
    for(char c = 'A' ; c <= 'B' ; c++){
        curr_str.push_back(c);

        if(i == n - 1){ // Da du do dai
            if(check(curr_str)){
                results.push_back(curr_str);
            }
        } else {
            Try(i + 1);
        }
        curr_str.pop_back();
    }
}

int main(){
    // Toi uu I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
        
    Try(0);
        
    cout << results.size() << "\n";
    for(string s : results){
        for(char c : s){
            cout << c << " ";
        }
        cout << "\n";
    }
    
    
    return 0;
}