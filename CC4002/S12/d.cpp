#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &input, int left, int right) {
    while (left <= right && input[left] == input[right]) ++left, --right;
    return left > right;
}
void processTestCase() {
    string s;
    cin >> s;
    int start = 0, end = s.size() - 1;

    while (start < end && s[start] == s[end]) ++start, --end;

    int maxRight, minLeft;
    for (maxRight = end; maxRight >= start; --maxRight)
        if (isPalindrome(s, start, maxRight)) break;

    for (minLeft = start; minLeft <= end; ++minLeft)
        if (isPalindrome(s, minLeft, end)) break;

    cout << s.substr(0, start)
         << ((maxRight - start > end - minLeft) ? s.substr(start, maxRight - start + 1) : s.substr(minLeft, end - minLeft + 1))
         << s.substr(end + 1)
         << "\n";
}
int main() {
    int testCases;
    cin >> testCases;
    while (testCases--)
        processTestCase();
    return 0;
}
