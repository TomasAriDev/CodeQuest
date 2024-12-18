#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<vector<long long>> dp_vec(n, vector<long long>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        dp_vec[i][i] = n * a[i];
    }

    for (int j = 1; j < n; ++j) {
        for (int l = 0; l + j < n; ++l) {
            int r = l + j;
            int vaso_c = n - (r - l);
            dp_vec[l][r] = max(vaso_c * a[l] + dp_vec[l + 1][r], vaso_c * a[r] + dp_vec[l][r - 1]);
        }
    }
    
    cout << dp_vec[0][n - 1] << endl;
    
    return 0;
}