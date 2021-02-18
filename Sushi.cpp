#include <iostream>
#include <algorithm>

using namespace std;
int prices[20], preferences[20];
int cache[201];
int iter_maxPref(int n, int m);

int main() {
	int C, m, n;
	cin >> C;
	for (int test_case = 0; test_case < C; ++test_case) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			cin >> prices[i] >> preferences[i];
			prices[i] /= 100;
		}
		m /= 100;
		cout << iter_maxPref(n, m) << endl;
	}
}

int iter_maxPref(int n, int m) {
	for (int price = 0; price <= m; ++price) {
		int& ret = cache[price % 201];
		ret = 0;
		for (int i = 0; i < n; ++i) {
			if (prices[i] <= price) {
				ret = max(ret, preferences[i] + cache[(price - prices[i]) % 201]);
			}
		}
	}

	return cache[m % 201];
}