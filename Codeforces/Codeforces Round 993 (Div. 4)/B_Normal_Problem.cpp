#include <bits/stdc++.h>
using namespace std; 
int main() {
    int t; cin >> t;
    vector<string> n(t);
    for (int i=0; i<t; i++){
        cin >> n[i];
    }
    unordered_map<char,char> umap = {
        {'p', 'q'},
        {'q', 'p'}
    };
    for (int i=0; i<t; i++){
        reverse(n[i].begin(), n[i].end());
        for (char &c: n[i]){
            if (umap.find(c)!=umap.end()){
                c = umap[c];
            }
        }
        cout << n[i] << endl;
    }
    return 0;
}   