#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // Dos enteros
    int n,k;
    cin >> n >> k;

    // n enteros t_i: cantidad de tiempo en imprimir la figura i
    vector<int> t(n);
    for (int i=0; i<n; i++) {
        cin >> t[i];
    }

    // limites de busqueda binaria sobre T
    ll low = 0;
    ll hi = 1e18;
    ll resp = 1e18;

    // mientras no coincidan los topes
    while (low <= hi) {
        // ubicamos nuestro mid 
        ll mid = (low + hi)/2;
        ll total = 0;
        // calculamos el total por elemento
        for (int j=0; j<n; j++) {
            total += min(mid/t[j], (ll)1e9);
            if (total>=k) {
                resp = mid;
                break;
            }
        }
        
        if (mid == resp) hi = mid-1;
        else low = mid+1;
    }

    cout << resp;
}