#include <bits/stdc++.h>
using namespace std; 
int main() {
    int t;
    cin >> t;
    vector<int> N(t);
    for (int i=0; i<t; i++){
        cin >> N[i];
    }
    for (int j=0; j<t; j++) {
        cout << N[j] - 1 << endl;
    } 
    return 0;

} 