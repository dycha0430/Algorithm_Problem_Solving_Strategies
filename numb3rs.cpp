#include <iostream>
#include <iomanip>

using namespace std;

bool isPath[50][50];
double cache[50][101];
int n, d, p, t, q;

double probability_hiding(int start, int days);
int main() {
	int C;
	cin >> C;
	for (int test_case = 0; test_case < C; ++test_case) {
		cin >> n >> d >> p;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> isPath[i][j];
			}
		}

		cin >> t;

		cout << fixed << setprecision(8);
		for (int i = 0; i < t; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k <= d; ++k) {
					cache[j][k] = -1;
				}
			}

			cin >> q;
			cout << probability_hiding(p, d) << " ";
		}

		cout << endl;
	}
}

/* Return probability that Dr. Dunibal will be hiding 
 * in 'q' village after 'days' days from 'start' village.
 */
double probability_hiding(int start, int days) {
	if (days == 0) {
		return start == q;
	}

	// Memoization.
	double& ret = cache[start][days];
	if (ret != -1) return ret;

	ret = 0;
	int pathNum = 0;
	for (int i = 0; i < n; ++i) {
		if (isPath[start][i]) {
			pathNum++;
			ret += probability_hiding(i, days - 1);
		}
	}
	
	if (pathNum == 0) return start == q;

	return ret /= pathNum;
}