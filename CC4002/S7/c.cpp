#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n, k;cin >> n >> k;
    
    vector<int> secuencia(n);
    for (int i = 0; i < n; i++) {
        cin >> secuencia[i];
    }
    
    unordered_set<int> diferencia_permitida;
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        diferencia_permitida.insert(d);
    }
    
    unordered_map<int, int> max_sec;
    
    int max_subsec = 1;
    
    for (int i = 0; i < n; i++) {
        int si = secuencia[i];
        max_sec[si] = max(max_sec[si], 1);
        for (int d : diferencia_permitida) {
            int prev_num = si - d;
            if (max_sec.find(prev_num) != max_sec.end()) {
                max_sec[si] = max(max_sec[si], max_sec[prev_num] + 1);
            }
        }
        
        max_subsec = max(max_subsec, max_sec[si]);
    }
    cout << max_subsec << endl;
    
    return 0;
}