#include <iostream>
#include <algorithm>

using namespace std;

long long combination(int n, int r);
long long solution(int n);
long long solution2(int n);

long long cache[101][101];
long long cache2[101];
int main() {
	int C, n;
	cin >> C;

	for (int i = 0; i < 101; ++i) {
		for (int j = 0; j < 101; ++j)
			cache[i][j] = -1;
		cache2[i] = -1;
	}

	for (int test_case = 0; test_case < C; test_case++) {
		cin >> n;

		cout << solution(n) << endl;
	}
}

/* Return number of cases of filling 2xn blocks using 2x1 or 1x2 blocks. */
long long solution(int n) {
	long long ret = 0;
	int verti, total;

	// If n is odd, number of vertical blocks(2x1) should be even.
	verti = n % 2 ? 1 : 0;

	// For all possible number of vertical and horizontal blocks, cacluate number of cases using combination.
	for (; verti <= n; verti += 2) {
		total = (n - verti) / 2 + verti;
		ret += (combination(total, verti));
	}

	return ret % 1000000007;
}

/* Return result of combination nCr */
long long combination(int n, int r) {
	if (n == r || r == 0) return 1;

	long long& ret1 = cache[n - 1][r - 1];
	long long& ret2 = cache[n - 1][r];

	return ((ret1 == -1 ? ret1 = combination(n - 1, r - 1) : ret1) + (ret2 == -1 ? ret2 = combination(n - 1, r) : ret2)) % 1000000007;
}

/* Another solution */
long long solution2(int n) {
	if (n < 0) return 0;
	if (n == 0) return 1;

	long long& ret = cache2[n];
	if (ret != -1) return ret;

	return ret = (solution2(n - 1) + solution2(n - 2)) % 1000000007;
}
