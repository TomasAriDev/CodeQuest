#include <bits/stdc++.h>
using namespace std;

string get_string(string s, int k) {
	while ((int)s.size() < k) s = s + s;
	while ((int)s.size() > k ) s.pop_back();
	return s;
}
int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string prefix = "";
	prefix += s[0];
	string minm = get_string(prefix, k);
	for (int i = 1; i < s.size(); i ++) {
		if (s[i] > s[0]) break;
		prefix += s[i];
		minm = min (minm, get_string(prefix, k));
	}
	cout << minm << endl;
	return 0;
}
