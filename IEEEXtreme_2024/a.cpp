#include <bits/stdc++.h>
using namespace std;

int main () {

    int n; cin >> n;
    vector<pair<int,int>> t(n);
    bool error = false;

    for (int i=0; i<n; i++) {
        cin >> t[i].first >> t[i].second;
    }

    sort(t.begin(),t.end()); 

    int a_max_grupo1 = t[0].first;
    int b_min_grupo1 = t[0].first;

    for (const auto& t_i : t) {
        if (t_i.first <= b_min_grupo1) {
            a_max_grupo1 = max(a_max_grupo1, t_i.first);
            b_min_grupo1 = min(b_min_grupo1, t_i.second);
        } 
        else {
            
            int a_max_grupo2 = t_i.first;
            int b_min_grupo2 = t_i.second;

            if (a_max_grupo1 <= b_min_grupo2 && a_max_grupo2 >= b_min_grupo1) {
                cout << b_min_grupo1 << " " << a_max_grupo2 << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
