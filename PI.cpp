#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int calculate_diff(int start, int len);
int min_difficulty(int start);

const int MAX = 100000;
string str;
int cache[10000];
int main() {
	int C;
	cin >> C;
	for (int test_case = 0; test_case < C; test_case++) {
		cin >> str;
		memset(cache, -1, sizeof(cache));

		cout << min_difficulty(0) << endl;
	}
}

/* Caculate difficulty of a substring of length len starting at start. */
int calculate_diff(int start, int len) {
	// All numbers are same.
	if (str.substr(start, len) == string(len, str[start])) return 1;

	// Monotonically increase. 
	bool ok = true;
	for (int i = 1; i < len; i++) {
		if (str[start + i] - str[start + i - 1] != 1) {
			ok = false;
			break;
		}
	}
	if (ok) return 2;

	// Monotonically decrease. 
	ok = true;
	for (int i = 1; i < len; i++) {
		if (str[start + i] - str[start + i - 1] != -1) {
			ok = false;
			break;
		}
	}
	if (ok) return 2;

	// Two numbers appear alternately. 
	ok = true;
	for (int i = 2; i < len; i++) {
		if (str[start + i] != str[start + i - 2]) {
			ok = false;
			break;
		}
	}
	if (ok) return 4;

	// Isometric sequence. 
	ok = true;
	int diff = str[start + 1] - str[start];
	for (int i = 1; i < len; i++) {
		if (str[start + i] - str[start + i - 1] != diff) {
			ok = false;
			break;
		}
	}
	if (ok) return 5;

	// Otherwise
	return 10;
}

/* Caculate minimum difficulty of string str starting start.*/
int min_difficulty(int start) {
	int remain_len = str.length() - start;
	
	// Case: remaining length of string is less than 6
	if (remain_len < 6) return calculate_diff(start, remain_len);

	// Memoization
	int& ret = cache[start];
	if (ret != -1) return ret;

	ret = MAX;
	/* Minimum difficulty is minimum of difficulty of the pieces cut into lengths of 3, 4, 5
	 * plus the minimum difficulty of rest of the string.
	 */
	for (int len = 3; len <= min(remain_len - 3, 5); len++) {
		ret = min(ret, min_difficulty(start + len) + calculate_diff(start, len));
	}

	return ret;
}