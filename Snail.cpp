#include <iostream>

using namespace std;

int n, m;
double cache[1001][1001];

double snail(int days, int height);
int main() {
	int C;
	cin >> C;

	for (int test_case = 0; test_case < C; ++test_case) {
		cin >> n >> m;
		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= n; ++j)
				cache[i][j] = -1;
		}
		
		cout.setf(ios::fixed);
		cout.precision(10);
		cout << snail(0, 0) << endl;
	}
}

/* Return probability that a snail will escape the well 
 * when the snail went up 'height' after 'days'.
 */
double snail(int days, int height) {
	if (days == m) return height >= n ? 1 : 0;
	if (height >= n) return 1;

	double& ret = cache[days][height];
	if (ret != -1) return ret;

	return ret = 0.25 * snail(days + 1, height + 1) + 0.75 * snail(days + 1, height + 2);
}