#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    int k;
    cin >> n >> k;

    vector<int> elasticidades(k);
    for (int i = 0; i < k; i++) {
        cin >> elasticidades[i];
    }

    unordered_set<long long> hitTiles;

    // Para cada elasticidad, marcamos los tiles golpeados
    for (int elasticidad : elasticidades) {
        for (long long tile = elasticidad; tile <= n; tile += elasticidad) {
            hitTiles.insert(tile);
        }
    }

    cout << hitTiles.size() << endl;
    return 0;
}
