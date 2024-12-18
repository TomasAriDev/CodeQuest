
int main() {
    int n;
    cin >> n;
    vector<int> r1(2, -1000);  
    vector<int> r2(2, -1000);  
    bool error = false;

    while (n--) {
        int a, b;
        cin >> a >> b;

        // Caso base: si r1 no ha sido asignado, lo asignamos al primer intervalo.
        if (r1[0] == -1000) {
            r1[0] = a;
            r1[1] = b;
        }
        // Si el intervalo cae dentro de r1, lo ajustamos.
        else if (a <= r1[1] && b >= r1[0]) {
            r1[0] = max(r1[0], a);
            r1[1] = min(r1[1], b);
        }
        // Si el intervalo cae fuera de r1 y r2 aún no ha sido asignado, lo asignamos a r2.
        else if (r2[0] == -1000) {
            r2[0] = a;
            r2[1] = b;
        }
        // Si el intervalo cae dentro de r2, lo ajustamos.
        else if (a <= r2[1] && b >= r2[0]) {
            r2[0] = max(r2[0], a);
            r2[1] = min(r2[1], b);
        }
        // Si el intervalo no encaja en ninguno de los dos refrigeradores, hay un error.
        else {
            error = true;
            break;
        }
    }

    if (error) {
        cout << -1 << endl;
    } else {
        // Asegurarse de que T1 <= T2, si no intercambiamos r1 y r2.
        if (r1[0] > r2[0]) swap(r1, r2);

        if (r2[0] == -1000) {  // Caso en el que solo se usa un refrigerador
            cout << r1[0] << " " << r1[0] << endl;
        } else {  // Ambos refrigeradores son necesarios
            cout << r1[0] << " " << r2[0] << endl;
        }
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int main() {
    int i,j; // temps refris
    int n; cin >> n; // num elementos
    vector<int> r1 = {-100,100};
    vector<int> r2 = {-100,100};
    bool ok = true;
    while (n--) {
        int a,b; cin >> a >> b;
        // ponemos r1
        if (r1[0]==-100 && r1[1]==100) {
            r1[0] = a;
            r1[1] = b;
        }
        // solo manejamos por r1
        else if ( (a<=r1[0] && (b>=r1[1] || b<=r1[1] ) ) || (a>=r1[0] && b<=r1[1]) || (a>=r1[0] && a<=r1[1] && b>=r1[1])) {
            r1[0] = max(a,r1[0]);
            r1[1] = min(b,r1[1]);
        }
        else if (((b<=r1[0]) || (a>=r1[1])) && (r2[0]==-100 && r2[1]==100)){
            r2[0] = a;
            r2[1] = b;
        }
        else if ((a<=r2[0] && b>=r2[1]) || (a>r2[0] && b<r2[1]) || (a<=r2[0] && b>=r1[0] && b<=r2[1]) || (a>=r2[0] && a<=r2[1] && b>=r2[1])) {
            r2[0] = max(a,r2[0]);
            r2[1] = min(b,r2[1]);
        }
        else {
            ok = false;
            break;
        }
    }
    if (r2[0]==-100) {
        i = r1[0];
        j = r1[0];
    }
    else {
        i = min(r1[0],r2[0]);
        j = max(r1[0],r2[0]);
    }
    if (ok || n==0) {
        cout << i << " " << j << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}





