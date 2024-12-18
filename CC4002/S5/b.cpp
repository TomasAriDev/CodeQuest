#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    // cantidad de casos 
    int t; cin >> t; 
    
    while (t--) {
        // n: columnas de coral
        // x: agua a ocupar
        int n,x; cin >> n >> x;

        // a_i: altura de el coral por columna
        vector<ll> a(n);
        for (ll i=0; i<n;i++) {
            cin >> a[i];
        }

        // limites de busqueda binaria sobre T
        ll low = 1;
        ll hi = *max_element(a.begin(),a.end())+x;
        ll resp = 1;

        // mientras no coincidan los topes
        while (low <= hi) {
            ll mid = (low + hi)/2;
            ll total = 0;    
            for (int j=0; j<n; j++) {

                if (a[j]<mid) total+=mid - a[j];

                if (total>x) {
                    break;
                }
            }
            if (total>x) hi = mid-1;
            else {
                resp = mid;
                low = mid+1;
            }
        }
        cout << resp << endl;
    }
}