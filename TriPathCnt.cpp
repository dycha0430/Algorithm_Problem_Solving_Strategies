#include <iostream>
#include <algorithm>

using namespace std;

int tri[100][100];
int cache[100][100];
int cache2[100][100];

int solve(int n, int row, int col);
int tri_path(int n, int row, int col);
int main() {
	int C, n;
	cin >> C;

	for (int test_case = 0; test_case < C; ++test_case) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				cin >> tri[i][j];
				cache[i][j] = -1;
				cache2[i][j] = -1;
			}
		}

		tri_path(n, 0, 0);
		cout << solve(n, 0, 0) << endl;	
	}
}

/* Find number of cases of max triangle path starting at (row, col). */
int solve(int n, int row, int col) {
	// When reach the last line, number of cases is always 1.
	if (row == n - 1) return 1;
	
	// Memoization.
	int& ret = cache2[row][col];
	if (ret != -1) return ret;
	
	// Find number of cases starting immediately below and below right.
	int below = solve(n, row + 1, col);
	int below_right = solve(n, row + 1, col + 1);
	
	int below_max = cache[row + 1][col];
	int below_right_max = cache[row + 1][col + 1];
	
	// If max triangle paths starting below and right below is equal, add two number of cases.
	if (below_max == below_right_max) return ret = below + below_right;
	// Else, take the number of cases on the side with the bigger path. 
	else if (below_max < below_right_max) return ret = below_right;
	else return ret = below;
}

/* Find max sum of numbers of triangle path starting at (row, col). */
int tri_path(int n, int row, int col) {
	int& ret = cache[row][col];

	// When reach the last line, directly return the number. 
	if (row == n - 1) return ret = tri[row][col];

	/* If the max sum starting at (row, col) is already computed,
	 * return computed sum.
	 */
	if (ret != -1) return ret;

	/* Max sum of path starting at this location is the number at the current location plus
	 * the higher of sum of paths starting immediately below or below right.
	 */
	return ret = tri[row][col] + max(tri_path(n, row + 1, col), tri_path(n, row + 1, col + 1));
}