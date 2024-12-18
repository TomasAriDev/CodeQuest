#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<long long> vector(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            vector[i] = a[i]; 
            int sig_pos = i + a[i];
            if (sig_pos < n) {
                vector[i] += vector[sig_pos];
            }
        }
        long long max_moscas = *max_element(vector.begin(), vector.end());
        cout << max_moscas << endl;
    }
    
    return 0;
}