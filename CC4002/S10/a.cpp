#include <bits/stdc++.h>
#include <string>
#define MAXN 1000000+10
using namespace std;

string parentheses;

struct SegmentTreeNode {
    int maxPairs = 0;
    int openCount = 0;
    int closeCount = 0;
};

SegmentTreeNode segmentTree[4*MAXN];

int min(int a, int b) {
    return (a <= b) ? a : b;
}

void insert(int nodeIndex, int start, int end, int position, char bracket) {
    if (position < start || position > end) return;
    if (bracket == '(') segmentTree[nodeIndex].openCount++;
    if (bracket == ')') {
        if (segmentTree[nodeIndex].openCount > 0) {
            segmentTree[nodeIndex].maxPairs++;
            segmentTree[nodeIndex].openCount--;
        } else {
            segmentTree[nodeIndex].closeCount++;
        }
    }
    if (start == end) return;
    int mid = (start + end) / 2;
    insert(2 * nodeIndex, start, mid, position, bracket);
    insert(2 * nodeIndex + 1, mid + 1, end, position, bracket);
}

SegmentTreeNode queryMaxPairs(int nodeIndex, int start, int end, int left, int right) {
    SegmentTreeNode total;
    if (right < start || left > end) return total;
    if (left <= start && end <= right) return segmentTree[nodeIndex];
    int mid = (start + end) / 2;
    SegmentTreeNode leftResult = queryMaxPairs(2 * nodeIndex, start, mid, left, right);
    SegmentTreeNode rightResult = queryMaxPairs(2 * nodeIndex + 1, mid + 1, end, left, right);
    
    int matchedPairs = min(leftResult.openCount, rightResult.closeCount);
    total.maxPairs = leftResult.maxPairs + rightResult.maxPairs + matchedPairs;
    total.openCount = leftResult.openCount + rightResult.openCount - matchedPairs;
    total.closeCount = leftResult.closeCount + rightResult.closeCount - matchedPairs;
    return total;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int length, queries, left, right;
    cin >> parentheses;
    length = parentheses.length();
    cin >> queries;
    for (int i = 1; i <= length; i++)
        insert(1, 1, length, i, parentheses[i - 1]);
    for (int i = 1; i <= queries; i++) {
        cin >> left >> right;
        cout << 2 * queryMaxPairs(1, 1, length, left, right).maxPairs << endl;
    }
    return 0;
}
