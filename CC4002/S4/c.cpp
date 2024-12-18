#include <bits/stdc++.h>
using namespace std;

int main() {
    // cantidad de canciones
    int n; cin >> n;
    // ID cancion
    vector<int> a(n);
    for (int i=0; i<n;i++) {
        cin >> a[i];
    }

    unordered_map<int, int> s;
    int h=0;
    int in=0;
    for (int i=0;i<n;i++) {
        // estoy en el map
        if (s.find(a[i]) != s.end()) {  
            in = max(s[a[i]] + 1, in);
        }
        s[a[i]] = i;

        h = max(h, i-in+1);

    }
    cout << h << endl;

    return 0;    
}
