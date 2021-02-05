#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int N, K;
int arr[500], cache[500];
double len_cache[500][501];
vector<pair<int, int>> sorted_arr;

void print_arr(int min_index, int len, int k, int prev);
double num_LIS(int start, int len);
int get_LIS(int start);

int main() {
	int C;
	cin >> C;
	for (int test_case = 0; test_case < C; ++test_case) {
		cin >> N >> K;
		
		sorted_arr.clear();
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= N; ++j)
				len_cache[i][j] = -1;
			cache[i] = -1;
			cin >> arr[i];
			sorted_arr.push_back(make_pair(arr[i], i));
		}
		sort(sorted_arr.begin(), sorted_arr.end());

		int LIS_len = 0;
		for (int i = 0; i < N; ++i) {
			LIS_len = max(LIS_len, get_LIS(i));
		}
		
		int LIS_num = 0;
		for (int i = 0; i < N; ++i) {
			LIS_num += num_LIS(i, LIS_len);
		}

		cout << LIS_len << endl;
		print_arr(0, LIS_len, K, 0);
		cout << endl;

		
	}
}

/* Print kth LIS of lenghth len in an array 
 * with an index greater than 'min_index'.
 * Assume that previous number of finding LIS is 'prev'.
 */
void print_arr(int min_index, int len, int k, int prev) {
	
	for (int i = 0; i < N; ++i) {
		int index = sorted_arr.at(i).second;
		int num = sorted_arr.at(i).first;
		if (index >= min_index && num > prev) {
			if (len_cache[index][len] < k) k -= len_cache[index][len];
			else {
				cout << num << " ";
				return print_arr(index, len - 1, k, num);
			}
		}
	}
	
}

/* Return number of LIS with length 'len' in the array starting 'start'. */
double num_LIS(int start, int len) {
	double& ret = len_cache[start][len];
	if (ret != -1) return ret;

	// If length is 1, there is only one LIS, which is itself.
	if (len == 1) return ret = 1;

	ret = 0;
	
	for (int i = start + 1; i < N; ++i) {
		if (arr[start] < arr[i]) ret += num_LIS(i, len - 1);
	}
	
	return ret;
}

/* Find longest length of increasing sequence starting from `start` */
int get_LIS(int start) {
	if (start == N - 1) return 1;

	int& ret = cache[start];
	if (ret != -1) return ret;
	
	int maxLIS = 1;
	for (int i = start + 1; i < N; i++) {
		if (arr[i] > arr[start]) {
			maxLIS = max(maxLIS, 1 + get_LIS(i));
		}
	}

	return ret = maxLIS;
}