#include <bits/stdc++.h>
using namespace std;

// kmp algorithm
vector<int> pi_kpm(const string &str) {
	int n = (int)str.size();
	vector<int> pi_res(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && str[j] != str[i]) { j = pi_res[j - 1]; }
		if (str[i] == str[j]) { j++; }
		pi_res[i] = j;
	}
	return pi_res;
}

int main() {
	string P, T;
	cin >> T >> P;
	string S = P + '#' + T;
	vector<int> pi_values = pi_kpm(S);
	int count = 0;
	for (int l : pi_values) {
		if (l == P.size()) { count++; }
	}
	cout << count << '\n';
}
