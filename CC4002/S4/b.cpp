#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Función para calcular la suma de los dígitos de un número
int sumar_digitos(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    priority_queue<int> campo;
    vector<int> flores(N);

    for (int i = 0; i < N; ++i) {
        cin >> flores[i];
        campo.push(flores[i]);
    }

    int gertrude_polen = 0;
    int turnos = 0; // Contador de turnos

    while (!campo.empty()) {
        turnos++;
        int flor_max_polen = campo.top();
        campo.pop();

        int recolectado = sumar_digitos(flor_max_polen);

        if (turnos % K == 0) { 
            gertrude_polen += recolectado;
        }

        int polen_restante = flor_max_polen - recolectado;
        if (polen_restante > 0) {
            campo.push(polen_restante);
        }
    }

    cout << gertrude_polen << "\n";
    return 0;
}
