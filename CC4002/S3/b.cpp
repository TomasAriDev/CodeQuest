#include <bits/stdc++.h>
using namespace std;

int main() {
    // casos 
    int t;
    cin >> t;

    while (t--) {
        // input del string
        string s;
        cin >> s;
        // lo damos vuelta por conveniencia 
        reverse(s.begin(), s.end());  

        string result;
        int lower_del = 0, upper_del = 0;
        
        for (char c : s) {
            if (c == 'b') {
                lower_del++;  
            } else if (c == 'B') {
                upper_del++;  
            } else if (islower(c)) {
                if (lower_del > 0) {
                    lower_del--;  
                } else {
                    result.push_back(c);  
                }
            } else if (isupper(c)) {
                if (upper_del > 0) {
                    upper_del--;  
                } else {
                    result.push_back(c);  
                }
            }
        }

        reverse(result.begin(), result.end());  
        cout << result << '\n';
    }

    return 0;
}
