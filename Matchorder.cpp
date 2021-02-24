#include <iostream>
#include <algorithm>

using namespace std;

int N;
int rRating[100], kRating[100];
int max_winnings();
int main() {
	int C;
	cin >> C;
	for (int test_case = 0; test_case < C; ++test_case) {
		cin >> N;
		for (int i = 0; i < N; ++i) cin >> rRating[i];
		for (int i = 0; i < N; ++i) cin >> kRating[i];

		sort(rRating, rRating + N);
		sort(kRating, kRating + N);

		cout << max_winnings() << endl;
	}
}

/* Return maximum count that korea can win. */
int max_winnings() {
	int ret = 0;
	int j = 0;

	// Beat russian players with lowest ratings in turn.
	for (int i = 0; i < N; ++i) {
		for (; j < N; ++j) {
			if (rRating[i] <= kRating[j]) {
				ret++;
				j++;
				break;
			}
		}
	}

	return ret;
}