#include <iostream>
#include <algorithm>

using namespace std;
int N, K, M;
int Li[50];
double T[50][50];
double cache[1000000][50];
double solve(int time, int songNum);
double solve2(int time, int songNum);

int main() {
	int C, Qi;
	double Answer;
	cin >> C;

	cout << fixed;
	cout.precision(8);
	for (int test_case = 0; test_case < C; ++test_case) {
		cin >> N >> K >> M;
		for (int i = 0; i < N; ++i) cin >> Li[i];
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) cin >> T[i][j];
		}

		for (int i = 0; i <= K; ++i) {
			for (int j = 0; j < N; ++j)
				cache[i][j] = -1;
		}

		for (int i = 0; i < M; ++i) {
			Answer = 0;
			cin >> Qi;
			
			cout << solve2(K, Qi) << " ";
		}

		cout << endl;
		
	}
}

/* Return possibility that 'songNum'th song is being played at 'time' */
double solve(int time, int songNum) {
	// The first song is 0th song.
	if (time == 0) return T[0][songNum];
	else if (time < 0) return 0;
	
	double& ret = cache[time][songNum];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < N; ++i) {
		ret += solve(time - Li[i], i) * T[i][songNum];
	}

	return ret;
}

/* This solution reduced memory space used. */
double solve2(int time, int songNum) {
	double cache2[5][50];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < Li[0]; ++j)
			cache2[j][i] = 0;
		cache2[Li[0]][i] = T[0][i];
	}

	for (int i = Li[0] + 1; i <= K; ++i) {
		for (int j = 0; j < N; ++j) {
			cache2[i % 5][j] = 0;
			for (int k = 0; k < N; ++k) {
				if (i - Li[k] >= 0)
					cache2[i % 5][j] += cache2[(i - Li[k]) % 5][k] * T[k][j];
			}
		}
	}

	double ret = 0;
	for (int i = K; i > K - Li[songNum]; --i) {
		ret += cache2[i % 5][songNum];
	}

	return ret;
}