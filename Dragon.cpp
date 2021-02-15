#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char dragon_curve(int gen, int k, string str);

int n, p, l;
int main() {
	int C;
	cin >> C;

	for (int test_case = 0; test_case < C; ++test_case) {
		cin >> n >> p >> l;

		for (int i = p; i < p + l; ++i) {
			cout << dragon_curve(min(n, 0), i, "+FX+YF");
		}
		cout << endl;
	}
}

char dragon_curve(int gen, int k, string str) {
	if (gen == n) {
		return str[k];
	}
	double boundary = 3 * pow(2, n - gen);
	
	int mid = str.length() / 2;
	if (k < boundary) str = str.substr(0, mid);
	else {
		str = str.substr(mid, str.length());
		k -= boundary;
	}
	
	string replace_str = str.substr(1) == "FX" ? "FX+YF" : "FX-YF";
	str.replace(1, 2, replace_str);

	return dragon_curve(gen + 1, k, str);
}
