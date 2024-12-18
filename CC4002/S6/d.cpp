#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    int n,k; 
    cin >> n >> k;
    vector<int> x(n);    
    int value=0;
    for (int i=0;i<n;i++) {
        cin >> x[i];
        value = max(value,x[i]);
    }

    ll low = value;
    ll hi = 1e18;
    ll resp = 1e18;

    while (low<=hi) {
        ll mid = (low+hi)/2;
        int block = 1;
        ll sum = 0;
        for (int j=0; j<n;j++){
            if (sum + x[j] > mid) {
                sum=0;
                block++;
            }
            sum+=x[j];
        }
        if (block > k) {
            low = mid +1;
        }
        else {
            if (mid < resp) resp=mid;
            hi = mid-1;
        }
    }
    cout << resp;
    return 0;
}