#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {

    int n,k,l; cin >> n >> k >> l;

    ll sum = 0;

    for (int i=0; i<n; i++) {
        if (2*l-k<=0) {
            sum+=4LL*l*l;
        }
        else if (sum==0) {
            sum+=4LL*l*l;
        }
        else {
            sum += 4LL* l * l - (2LL * l - k) * (2LL * l - k);
        }
    }

    cout << sum << endl;
    return 0;

}

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main () {
    int n, k, l; 
    cin >> n >> k >> l;

    ull sum = 0;
    ull x1 = 4ULL * l * l;
    ull x2 = (2ULL * l - k) * (2ULL * l - k);

    if (2 * l - k <= 0) {
        sum = n * x1;  
    } else {
        sum = x1;  
        for (int i = 1; i < n; i++) { 
            sum += x1 - x2;
        }
    }

    cout << sum << endl;
    return 0;
}
