#include <iostream>

using namespace std;

const int MOD = 10000000;

int solve(int n);
int poly(int n, int first);
int cache[101][101];

int main() {
	int C, n;
	cin >> C;

	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j)
			cache[i][j] = -1;
	}

	for (int test_case = 0; test_case < C; ++test_case) {
		cin >> n;

		cout << solve(n) << endl;

	}
}

int solve(int n) {
	int Answer = 0;
	for (int i = 1; i <= n; ++i) {
		Answer += poly(n, i);
		Answer %= MOD;
	}
}

/* Return possible number of monotone polyomino consisting of n squares
 * and with the 'first` number of squares in the top row.
 */
int poly(int n, int first) {
	if (n == first) return 1;

	int& ret = cache[n][first];
	if (ret != -1)return ret;
	
	ret = 0;
	for (int i = 1; i <= n - first; ++i) {
		ret += (first + i - 1) * poly(n - first, i);
		ret %= 10000000;
	}

	return ret % 10000000;
}