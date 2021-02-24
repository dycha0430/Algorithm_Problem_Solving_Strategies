#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int M[10000];
vector<pair<int, int>> lunchTime;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}
int minimized_lunch();

int main() {
	int T, E;
	cin >> T;
	for (int test_case = 0; test_case < T; ++test_case) {
		cin >> N;
		lunchTime.clear();
		for (int i = 0; i < N; ++i) cin >> M[i];
		for (int i = 0; i < N; ++i) {
			cin >> E;
			lunchTime.push_back(make_pair(E, M[i]));
		}

		// Sort by Eating time in descending order.
		sort(lunchTime.begin(), lunchTime.end(), compare);

		cout << minimized_lunch() << endl;
	}
}

/* Return minimized lunch time */
int minimized_lunch() {
	int i, partSum = 0;
	vector<pair<int, int>>::reverse_iterator iter;
	int Answer = 0;

	/* Find the maximum amount of time to eat a food 
	 * that exceeds the microwave usage time required
	 * after that food has been heated.
	 */
	for (i = 0, iter = lunchTime.rbegin(); i < N; ++i, ++iter) {
		Answer = max(Answer, (*iter).first - partSum);
		partSum = partSum + (*iter).second;
	}

	/* Minimized lunch time is the sum of the total usage time
	 * of the microwave and the value obtained above.
	 */
	return partSum + Answer;
}