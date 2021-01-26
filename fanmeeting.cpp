#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> multiply(vector<int>& a, vector<int>& b);
void add(vector<int>& a, vector<int>& b, int k);
void sub(vector<int>& a, vector<int>& b);
vector<int> karatsuba(vector<int>& a, vector<int>& b);
int main() {
	int C, answer;
	string mem, fan;

	cin >> C;
	for (int test_case = 0; test_case < C; test_case++) {
		answer = 0;
		cin >> mem >> fan;
		
		vector<int> mem_vec(mem.size()), fan_vec(fan.size());
		
		for (int i = 0; i < mem.size(); i++) {
			if (mem[i] == 'F') mem_vec[i] = 0;
			else mem_vec[i] = 1;
		}
		for (int i = 0; i < fan.size(); i++) {
			if (fan[fan.size()-i-1] == 'F') fan_vec[i] = 0;
			else fan_vec[i] = 1;
		}

		vector<int> ret = karatsuba(mem_vec, fan_vec);

		for (int i = mem.size() - 1; i < fan.size(); i++) {
			if (ret[i] == 0) answer++;
		}

		cout << answer << endl;

	}
}

vector<int> multiply(vector<int>& a, vector<int>& b) {
	vector<int> ret(a.size() + b.size() + 1, 0);

	for (int i = 0; i < a.size(); i++) {		
		for (int j = 0; j < b.size(); j++) {
			ret[i+j] += a[i] * b[j];
		}
	}
	
	return ret;
}

void add(vector<int>& a, vector<int>& b, int k) {
	a.resize(max(a.size(), b.size() + k));

	int i;
	for (i = k; i < b.size() + k; i++) {
		a[i] += b[i - k];
	}
}

void sub(vector<int>& a, vector<int>& b) {
	a.resize(max(a.size(), b.size()+1));

	for (int i = 0; i < b.size(); i++) {
		a[i] -= b[i];
	}
}

vector<int> karatsuba(vector<int>& a, vector<int>& b) {
	int aSize = a.size(), bSize = b.size();
	if (aSize < bSize) return karatsuba(b, a);

	if (aSize == 0 || bSize == 0) return vector<int>();

	if (aSize < 50) {
		return multiply(a, b);
	}

	int aHalf = aSize / 2;
	vector<int> a0(a.begin(), a.begin() + aHalf);
	vector<int> a1(a.begin() + aHalf, a.end());
	vector<int> b0(b.begin(), b.begin() + min(aHalf, bSize));
	vector<int> b1(b.begin() + min(aHalf, bSize), b.end());

	vector<int> z0 = karatsuba(a0, b0);
	vector<int> z1 = karatsuba(a1, b1);

	add(a0, a1, 0);
	add(b0, b1, 0);
	vector<int> z2 = karatsuba(a0, b0);
	
	sub(z2, z0);
	sub(z2, z1);

	vector<int> ret;
	add(ret, z1, 0);
	add(ret, z0, 2 * aHalf);
	add(ret, z2, aHalf);

	return ret;
}

