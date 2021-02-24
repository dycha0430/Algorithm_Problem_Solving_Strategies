#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n;
priority_queue<int, vector<int>, greater<int>> strLen;
int solve();

int main() {
	int C, tmp;
	cin >> C;
	for (int test_case = 0; test_case < C; ++test_case) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			strLen.push(tmp);
		}

		cout << solve() << endl;
	}
}

/* Return minimum cost to concat strings. */
int solve() {
	int a, b, Answer = 0;
	// Always pick two shortest lengths.
	while (true) {
		a = strLen.top();
		strLen.pop();
		b = strLen.top();
		strLen.pop();
		int sum = a + b;
		Answer += sum;
		
		if (strLen.empty()) break;
		strLen.push(sum);
	}

	return Answer;
}