#include <iostream>
using namespace std; 
int main() {

    // Input, peso de la sandia:
    int w; 
    cin >> w;
    
    // Condicionamos:
    if(w%2==0 && w!=2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}
