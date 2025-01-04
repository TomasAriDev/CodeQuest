#include <bits/stdc++.h>
using namespace std; 
int main() {

    int t; cin >> t;
    vector<vector<int>> matrix(t, vector<int>(4));

    for (int i =0;i<t;i++) {
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        vector<int> x(4);
        matrix[i]= {m,a,b,c};
    }

    for (int i=0; i<t; i++){
        int m, a, b, c, f1, f2, sum;
        m = matrix[i][0]*2;
        f1 = m/2; 
        f2 = m/2;
        a = matrix[i][1];
        b = matrix[i][2];
        c = matrix[i][3];
        sum = 0;

        if (f1 <= a){ 
            sum+=f1;
        }
        else {
            sum += a;
        }
        if (f2 <= b){
            sum+=f2;
        }
        else {
            sum += b;
        }
        if (sum+c<=m) {
            cout << sum+c << endl; 
        }
        else cout << m << endl; 
    }
    return 0;
}