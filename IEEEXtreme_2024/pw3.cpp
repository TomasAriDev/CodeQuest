#include <bits/stdc++.h>
using namespace std;

int main() {
    string n_toString;
    cin >> n_toString;
    
    // caso base 
    if (n_toString == "1") {
        cout << 0 << endl;  
        return 0;
    }
    
    double log_n = log10(stod(n_toString));   
    double log_3 = log10(3);           
    
    double x = log_n / log_3;
    long long x_round = round(x);
    
    string power_of_3 = to_string((long long)pow(3, x_round));
    
    if (power_of_3 == n_toString) {
        cout << x_round << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
    string n_toString;
    cin >> n_toString;

    if (n_toString == "1") {
        cout << 0 << endl;
        return 0;
    }
    string c_power = "3";
    int exp = 1;
    
    while (c_power.size() < n_toString.size() || (c_power.size() == n_toString.size() && c_power <= n_toString)) {
        if (c_power == n_toString) {
            cout << exp << endl;
            return 0;
        }
        int k = 0;
        for (int i = c_power.size() - 1; i >= 0; --i) {
            int num = (c_power[i] - '0') * 3 + k;
            c_power[i] = (num % 10) + '0';
            k = num / 10;
        }
        if (k > 0) {
            c_power.insert(c_power.begin(), k + '0');
        }

        exp++;
    }
    cout << -1 << endl;
    return 0;
}
