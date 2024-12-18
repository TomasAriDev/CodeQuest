#include <bits/stdc++.h>
using namespace std;

int contador_op(const vector<int>& freq_a, const vector<int>& freq_b) {
    int op = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        int diff = freq_a[c - 'a'] - freq_b[c - 'a'];
        if (diff > 0) op += diff;
    }
    return op;
}

int main() {
    // casos totales
    int t;
    cin >> t;

    while (t--) {
        // n: long cadena
        // q: n°consultas
        int n, q;
        cin >> n >> q;
        // strigns
        string a, b;
        cin >> a >> b;
        // matriz de elementos de un string 
        vector<vector<int>> freq_a(n + 1, vector<int>(26, 0));
        vector<vector<int>> freq_b(n + 1, vector<int>(26, 0));

        for (int i = 0; i < n; ++i) {
            freq_a[i + 1] = freq_a[i];
            freq_b[i + 1] = freq_b[i];
            freq_a[i + 1][a[i] - 'a']++;
            freq_b[i + 1][b[i] - 'a']++;
        }

        while (q--) {
            // rango del string a revisar
            int l, r;
            cin >> l >> r;
            l--; 

            vector<int> freq_l_a(26, 0), freq_l_b(26, 0);
            vector<int> freq_r_a(26, 0), freq_r_b(26, 0);

            
            for (char c = 'a'; c <= 'z'; ++c) {
                freq_l_a[c - 'a'] = freq_a[l][c - 'a'];
                freq_l_b[c - 'a'] = freq_b[l][c - 'a'];
                freq_r_a[c - 'a'] = freq_a[r][c - 'a'];
                freq_r_b[c - 'a'] = freq_b[r][c - 'a'];
            }

            
            for (char c = 'a'; c <= 'z'; ++c) {
                freq_l_a[c - 'a'] = freq_r_a[c - 'a'] - freq_l_a[c - 'a'];
                freq_l_b[c - 'a'] = freq_r_b[c - 'a'] - freq_l_b[c - 'a'];
            }

            int operaciones = contador_op(freq_l_a, freq_l_b);

            cout << operaciones << endl;
        }
    }

    return 0;
}