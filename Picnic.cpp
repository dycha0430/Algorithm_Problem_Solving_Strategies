#include <cstdio>
#include <iostream>
using namespace std;

int isFriend[10][10];
int hasPartner[10];
int Answer;

void findPartner(int i, int n);

int main() {
	int N, n, m, a, b;

	cin >> N;

	for (int test_case = 0; test_case < N; test_case++){
		Answer = 0;
		for (int i = 0; i < 10; i++) {
			hasPartner[i] = 0;
			for (int j = 0; j < 10; j++)
				isFriend[i][j] = 0;
		}
		cin >> n >> m;

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			isFriend[a][b] = 1;
			isFriend[b][a] = 1;
		}

		findPartner(0, n);

		cout << Answer << endl;

	}
}

void findPartner(int i, int n) {
	if (i == n - 1) {
		if (hasPartner[i]) Answer++;
		else return;
	}
	else if (hasPartner[i]) {
		return findPartner(i + 1, n);
	}
	else {
		for (int j = i + 1; j < n; j++) {
			if (isFriend[i][j] && !hasPartner[j]) {
				hasPartner[i] = 1;
				hasPartner[j] = 1;
				findPartner(i + 1, n);
				hasPartner[i] = 0;
				hasPartner[j] = 0;
			}
		}

		return;
	}
}
