#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int nums[100];
int prefix_sum[100];
int square_sum[100];
int cache[100][11];
int N;

int quantize(int start, int pieces);
int min_diff(int a, int b);

int main() {
	int C, S;
	cin >> C;
	for (int test_case = 0; test_case < C; test_case++) {
		cin >> N >> S;

		for (int i = 0; i < N; i++) cin >> nums[i];

		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= S; j++)
				cache[i][j] = -1;

		// Sort the array.
		sort(nums, nums + N);

		// Calculate prefix sum and sum of squares.
		prefix_sum[0] = nums[0];
		square_sum[0] = nums[0] * nums[0];
		for (int i = 1; i < N; i++) {
			prefix_sum[i] = prefix_sum[i - 1] + nums[i];
			square_sum[i] = square_sum[i - 1] + nums[i] * nums[i];
		}

		cout << quantize(0, S) << endl;
	}
}

/* Return minimum sum of squares of error of array `nums`
 * starting `start` and using up to `pieces` types numbers.
 */
int quantize(int start, int pieces) {
	if (pieces == 1) return min_diff(start, N - 1);
	if (start == N) return 0;

	// Memoization 
	int& ret = cache[start][pieces];
	if (ret != -1) return ret;

	ret = square_sum[N-1];
	// Check all possible cases and select minimum value.
	for (int i = start; i < N; i++) {
		ret = min(ret, min_diff(start, i) + quantize(i + 1, pieces - 1));
	}

	return ret;
}

/* Return minimum sum of squares of error from a to b 
 * through quantization using one number. 
 * Formula is cacluated through differentiation.
 */
int min_diff(int a, int b) {
	int sum, avg, ret;
	sum = a == 0 ? prefix_sum[b] : prefix_sum[b] - prefix_sum[a - 1];
	avg = int((double)sum / (double)(b - a + 1) + 0.5);
	
	
	ret = a == 0 ? square_sum[b] : square_sum[b] - square_sum[a - 1];
	ret -= 2 * avg * sum;
	ret += avg * avg * (b - a + 1);

	return ret;
}

