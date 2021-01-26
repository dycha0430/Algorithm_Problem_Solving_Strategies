#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxSize(vector<int>& heights, int left, int right);
int main() {
	int C, N, input;
	vector<int> heights;
	cin >> C;

	for (int test_case = 0; test_case < C; test_case++) {
		cin >> N;
		heights.clear();

		for (int i = 0; i < N; i++) {
			cin >> input;

			heights.push_back(input);
		}

		cout << getMaxSize(heights, 0, N-1) << endl;
	}
}

int getMaxSize(vector<int>& heights, int left, int right) {
	if (right == left) {
		return heights[left];
	}
	int half, curHeight, ret;

	half = (left + right) / 2;
	ret = max(getMaxSize(heights, left, half), getMaxSize(heights, half + 1, right));

	int l = half;
	int r = half + 1;

	curHeight = min(heights[l], heights[r]);
	ret = max(ret, curHeight * (r - l + 1));

	l--; r++;

	while (left <= l || r <= right) {
		if (left <= l && (right < r || heights[l] > heights[r])) {
			curHeight = min(curHeight, heights[l]);
			l--;
		}
		else {
			curHeight = min(curHeight, heights[r]);
			r++;
		}

		ret = max(ret, curHeight * (r - l - 1));
	}

	return ret;
}