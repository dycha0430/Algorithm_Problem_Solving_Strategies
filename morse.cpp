#include <iostream>

using namespace std;

int n, m;
int num_codes[101][101];
double cache[201][101];

void morse(int sh_dot, int long_dot, int k);
double combination(int n, int r);

int main() {
	int C, k;
	cin >> C;

	for (int i = 0; i < 201; ++i) {
		for (int j = 0; j < 101; ++j)
			cache[i][j] = -1;
	}

	for (int test_case = 0; test_case < C; ++test_case) {
		cin >> n >> m >> k;

		morse(m, n, k);
		cout << endl;
	}
}

/* Print 'k'th morse code when there is 
 * sh_dot short signals and long_dot long signals.
 */
void morse(int sh_dot, int long_dot, int k) {
	if (sh_dot == 0 || long_dot == 0) {
		for (int i = 0; i < long_dot; ++i) cout << '-';
		for (int i = 0; i < sh_dot; ++i) cout << 'o';

		return;
	}

	// Find number of morse codes starting with long signal.
	double comb = combination(sh_dot + long_dot - 1, sh_dot);
	
	// Morse code looking for starts with a long signal.
	if (k <= comb) {
		cout << '-';
		morse(sh_dot, long_dot - 1, k);
	}
	// Morse code looking for starts with a short signal.
	else {
		cout << 'o';
		morse(sh_dot - 1, long_dot, k - comb);
	}
}

/* Return result of combination nCr */
double combination(int n, int r) {
	if (n == r || r == 0) return 1;

	double& ret1 = cache[n - 1][r - 1];
	double& ret2 = cache[n - 1][r];

	return ((ret1 == -1 ? ret1 = combination(n - 1, r - 1) : ret1) + (ret2 == -1 ? ret2 = combination(n - 1, r) : ret2));
}