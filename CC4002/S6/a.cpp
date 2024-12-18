#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    sort(prices.begin(), prices.end());

    vector<int> op_order(n);

    int idx = 0;
    for (int i = 1; i < n; i += 2) {
        op_order[i] = prices[idx++];
    }
    for (int i = 0; i < n; i += 2) {
        op_order[i] = prices[idx++];
    }

    int empandas_god = 0;
    for (int i = 1; i < n - 1; i++) {
        if (op_order[i] < op_order[i - 1] && op_order[i] < op_order[i + 1]) {
            empandas_god++;
        }
    }

    cout << empandas_god << endl;

    for (int i = 0; i < n; i++) {
        cout << op_order[i] << " ";
    }
    cout << endl;

    return 0;
}