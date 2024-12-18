#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class FenwickTree {
public:
    FenwickTree(int n) : size(n) {
        tree.resize(n + 1, 0);
    }

    void update(int index, int delta) {
        while (index <= size) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    int range_query(int left, int right) {
        return query(right) - query(left - 1);
    }

private:
    int size;
    vector<int> tree;
};

ll count_difficulty_triplets(int n, const vector<int>& difficulties) {
    // Compresión de coordenadas
    vector<int> sorted_diffs = difficulties;
    sort(sorted_diffs.begin(), sorted_diffs.end());
    sorted_diffs.erase(unique(sorted_diffs.begin(), sorted_diffs.end()), sorted_diffs.end());

    // Mapear dificultades originales a índices comprimidos
    unordered_map<int, int> compressed_index;
    for (int i = 0; i < sorted_diffs.size(); ++i) {
        compressed_index[sorted_diffs[i]] = i + 1;
    }

    int max_compressed = sorted_diffs.size();
    FenwickTree l_tree(max_compressed);
    FenwickTree r_tree(max_compressed);

    vector<int> l_greater(n, 0);
    vector<int> r_less(n, 0);

    // Inicializar el r_tree con todos los elementos
    for (int difficulty : difficulties) {
        r_tree.update(compressed_index[difficulty], 1);
    }

    for (int j = 0; j < n; ++j) {
        int compressed_difficulty = compressed_index[difficulties[j]];
        r_tree.update(compressed_difficulty, -1);

        // Contar elementos mayores a la izquierda y menores a la derecha usando índices comprimidos
        l_greater[j] = l_tree.range_query(compressed_difficulty + 1, max_compressed);
        r_less[j] = r_tree.range_query(1, compressed_difficulty - 1);

        // Actualizar l_tree con el elemento actual
        l_tree.update(compressed_difficulty, 1);
    }

    ll difficulty_count = 0;
    for (int j = 0; j < n; ++j) {
        difficulty_count += (ll)l_greater[j] * r_less[j];
    }

    return difficulty_count;
}

int main() {
    int n;
    cin >> n;

    vector<int> difficulties(n);
    for (int i = 0; i < n; ++i) {
        cin >> difficulties[i];
    }

    cout << count_difficulty_triplets(n, difficulties) << endl;
    return 0;
}
