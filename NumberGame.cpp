#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INIT = -100000;
int solve(int left, int right);
int numbers[50];
int cache[50][50];

int main() {
	int C, n;
	cin >> C;
	
	for (int test_case = 0; test_case < C; ++test_case) {
		cin >> n;
		int num;
		for (int i = 0; i < n; ++i) {
			cin >> numbers[i];
			for (int j = i; j < n; ++j) cache[i][j] = INIT;
		}
		
		cout << solve(0, n - 1) << endl;
	}
}

int solve(int left, int right) {
	if (left > right) return 0;
	if (left == right) return numbers[right];

	int& ret = cache[left][right];
	if (ret != INIT) return ret;

	ret = 0;
	// Take a rightmost number.
	ret = numbers[right] - solve(left, right - 1);

	// Take a leftmost number.
	ret = max(ret, numbers[left] - solve(left + 1, right));

	// Erase right two numbers.
	ret = max(ret, -solve(left, right - 2));

	// Erase left two numbers.
	ret = max(ret, -solve(left + 2, right));

	return ret;
}