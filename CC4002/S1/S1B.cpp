#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size; // Leer el tamaño del arreglo
        
        vector<int> arr(size);
        vector<int> even;
        vector<int> odd;

        for (int i = 0; i < size; i++) {
            cin >> arr[i];
            if (arr[i] % 2 == 0) {
                even.push_back(i + 1); // Guardar índice del número par
            } else {
                odd.push_back(i + 1); // Guardar índice del número impar
            }
        }

        if (odd.size() >= 3) {
            // Si hay al menos 3 impares
            cout << "YES" << endl;
            cout << odd[0] << " " << odd[1] << " " << odd[2] << endl;
        } else if (even.size() >= 2 && odd.size() >= 1) {
            // Si hay al menos 2 pares y 1 impar
            cout << "YES" << endl;
            cout << even[0] << " " << even[1] << " " << odd[0] << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
