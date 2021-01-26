#include <iostream>
#include <algorithm>

using namespace std;

int tri[100][100];
int cache[100][100];

int tri_path(int n, int row, int col);
int main() {
	int C, n;

	cin >> C;
	for (int test_case = 0; test_case < C; test_case++) {
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				cache[i][j] = -1;
				cin >> tri[i][j];
			}
		}

		cout << tri_path(n, 0, 0) << endl;
	}
}

/* Find max sum of numbers of triangle path starting at (row, col). */
int tri_path(int n, int row, int col) {
	// When reach the last line, directly return the number. 
	if (row == n - 1) return tri[row][col];

	/* If the max sum starting at (row, col) is already computed,
	 * return computed sum. 
	 */
	int& ret = cache[row][col];
	if (ret != -1) return ret;

	/* Max sum of path starting at this location is the number at the current location plus
	 * the higher of sum of paths starting immediately below or below right.
	 */
	return ret = tri[row][col] + max(tri_path(n, row + 1, col), tri_path(n, row + 1, col + 1));
}