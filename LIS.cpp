#include <iostream>
#include <algorithm>

using namespace std;

int seq[500], cache[500];
int N;

int get_LIS(int start);
int main() {
	int C, Answer;

	cin >> C;
	for (int test_case = 0; test_case < C; test_case++) {
		cin >> N;
		
		for (int i = 0; i < N; i++) {
			cache[i] = -1;
			cin >> seq[i];
		}

		Answer = 0;
		for (int i = 0; i < N; i++) {
			Answer = max(Answer, get_LIS(i));
		}
		cout << Answer << endl;
	}
}

/* Find longest length of increasing sequence starting from `start` */
int get_LIS(int start) {
	// LIS starting last point is always 1.
	if (start == N - 1) return 1;

	// If already computed, return.
	int& ret = cache[start];
	if (ret != -1) return ret;

	/* For all bigger subsequrent nums, pick that number for next number of LIS.
	 * Get the maximum among them.
	 */
	int maxLIS = 1;
	for (int i = start + 1; i < N; i++) {
		if (seq[i] > seq[start]) {
			maxLIS = max(maxLIS, 1 + get_LIS(i));
		}
	}

	return ret = maxLIS;
}