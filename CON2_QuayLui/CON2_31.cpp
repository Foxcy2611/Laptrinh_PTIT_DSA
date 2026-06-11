#include <iostream>
#include <vector>
#include <string>

using namespace std;

// LỎ

int k, m, n;
char c[5][5];
vector<string> dic;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool DFS(int i, int j, const string& word, int idx, vector<vector<bool>>& visited){
    if(idx == word.length()){
        return true;
    }

    visited[i][j] = true;

    for(int d = 0 ; d < 8 ; d++){
        int nx = i + dx[d];
        int ny = j + dy[d];

        if(nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]){
            if(c[nx][ny] == word[idx]){
                if(DFS(nx, ny, word, idx + 1, visited)){
                    return true;
                }
            }
        }
    }

    visited[i][j] = false;
    return false;
}

void Solve(){
    cin >> k >> m >> n;
    dic.resize(k);

    for(int i = 0 ; i < k ; i++){
        cin >> dic[i];
    }

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> c[i][j];
        }
    }

    // Ý TƯỞNG CỦA BẠN: Dùng vector để giữ nguyên thứ tự gốc
    vector<string> res;
    
    for(string word : dic){
        bool found_word = false;
        for(int i = 0 ; i < m && !found_word ; i++){
            for(int j = 0 ; j < n && !found_word ; j++){
                if(c[i][j] == word[0]){
                    vector<vector<bool>> visited(m, vector<bool>(n, false));

                    if(DFS(i, j, word, 1, visited)){
                        found_word = true;
                        res.push_back(word); // Lưu vào vector
                    }
                }
            }
        }
    }
    
    if(res.empty()){
        cout << "-1\n";
    } else {
        for(int i = 0; i < res.size(); i++){
            cout << res[i];
            if(i < res.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n"; 
    }
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