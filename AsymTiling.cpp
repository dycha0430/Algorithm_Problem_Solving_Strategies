#include <iostream>

using namespace std;

long long cache[101];

long long solve(int n);
long long sym_tiling(int n);
long long tiling(int n);

int main() {
	int C, n;
	cin >> C;
	
	for (int i = 0; i < 101; ++i) cache[i] = -1;
	for (int test_case = 0; test_case < C; ++test_case) {
		cin >> n;

		cout << solve(n) << endl;
	}
}

/* Return number of asymmetrical tiling cases. */
long long solve(int n) {
	// Subtract the number of symmetric tiling cases from the total tiling cases. 
	return (tiling(n) - sym_tiling(n) + 1000000007) % 1000000007;
}

/* Return number of symmetrical tiling cases. */
long long sym_tiling(int n) {
	int sym = n/2 + (n % 2 ? 0 : 1);
	
	return tiling(sym);
}

/* Return number of cases of filling 2xn blocks using 2x1 or 1x2 blocks. */
long long tiling(int n) {
	if (n < 0) return 0;
	if (n == 0) return 1;

	long long& ret = cache[n];
	if (ret != -1) return ret;

	return ret = (tiling(n - 1) + tiling(n - 2)) % 1000000007;
}