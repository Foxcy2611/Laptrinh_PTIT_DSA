#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void Solve(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    
    unordered_set<string> wordSet;
    for(int i = 1 ; i <= n ; i++){
        string str;
        cin >> str;
        wordSet.insert(str);
    }

    if(s == t){
        cout << "1\n";
        return;
    }
    queue<pair<string, int>> q;
    q.push({s, 1});

    if(wordSet.count(s)){
        wordSet.erase(s);
    }

    while(! q.empty()){
        string word = q.front().first;
        int step = q.front().second;
        q.pop();

        if(word == t){
            cout << step << "\n";
            return;
        }

        for(int i = 0 ; i < word.length() ; i++){
            char ori = word[i];
            for(char c = 'A' ; c <= 'Z' ; c++){
                if(c == ori) continue;

                word[i] = c;
                if(wordSet.count(word)){
                    q.push({word, step + 1});
                    wordSet.erase(word);
                }
            }
            word[i] = ori;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
}