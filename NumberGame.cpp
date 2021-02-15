#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
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
			for (int j = i; j < n; ++j) cache[i][j] = -1;
		}
		
		cout << solve(0, n - 1) << endl;
	}
}

int solve(int left, int right) {
	if (left > right) return 0;
	if (left == right) return numbers[right];

	int& ret = cache[left][right];
	if (ret != -1) return ret;

	ret = 0;
	// Take a rightmost number.
	int num = numbers[right];
	ret = num - solve(left, right - 1);

	// Take a leftmost number.
	num = numbers[left];
	ret = max(ret, num - solve(left + 1, right));

	// Erase right two numbers.
	int num1 = numbers[right];
	int num2 = numbers[right - 1];
	ret = max(ret, -solve(left, right - 2));

	// Erase left two numbers.
	num1 = numbers[left];
	num2 = numbers[left + 1];
	ret = max(ret, -solve(left + 2, right));

	return ret;
}