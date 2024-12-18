#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    // numero de cajas
    int c;
    cin >> c;

    while (c--) {
        // cantidad numeros de la etiqueta
        // ej: 2 1 2 4 5 => "5" (nuestro numero)
        int n;
        cin >> n;

        // elementos de la etiqueta
        // ej: 2 1 2 4 5 (combinacion valida)
        vector<int> e(n);
        for (int i=0; i<n; i++) {
            cin >> e[i];
        }
        
        // numero de moldes por caja
        int m;
        cin >> m;
        vector<string> s(m);
        // 'm' strings por caja
        for (int j=0; j<m; j++) {
            cin >> s[j];
        }

        // resolucion:
        for (int k=0; k<m; k++) {
            // string tamaño equivocado, NO
            if (s[k].size() != n) {
                cout << "NO" << endl;
            }
            // string tamaño correcto
            else {
                set<int> number;
                set<char> character;
                map<char,int> auth;
                bool problem = false;
                for (int q=0; q<n; q++) {
                    character.insert(s[k][q]);
                    // nuestra letra no esta en el map, la agregamos
                    if (auth.find(s[k][q]) == auth.end()) {
                        number.insert(e[q]);
                        auth[s[k][q]] = e[q];
                    }
                    // nuestra letra esta en el map
                    else {
                        if (auth[s[k][q]] != e[q]) {
                            problem = true;
                            cout << "NO" << endl;
                            break;
                        }
                    }
                }

                if (!problem) {
                    if (number.size()!= character.size()) {
                    cout << "NO" << endl;
                    } 
                    else {
                    cout << "YES" << endl;
                    }  
                    
                }

            }
        }
    }
    return 0;
}


