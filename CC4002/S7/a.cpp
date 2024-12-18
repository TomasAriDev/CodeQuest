#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n,a,b,c; cin >> n >> a >> b >> c;

    vector<int> p_max(n + 1, -1);
    
    p_max[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        if (i >= a && p_max[i - a] != -1)
            p_max[i] = max(p_max[i], p_max[i - a] + 1);
        if (i >= b && p_max[i - b] != -1)
            p_max[i] = max(p_max[i], p_max[i - b] + 1);
        if (i >= c && p_max[i - c] != -1)
            p_max[i] = max(p_max[i], p_max[i - c] + 1);
    }
    cout << p_max[n] << endl;
    
    return 0;
}