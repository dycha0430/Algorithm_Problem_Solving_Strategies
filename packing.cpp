#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string name[100];
int volume[100];
int urgency[100];
int cache[100][1001];
int N, W;
vector<string> stuffs;

void get_stuffs(int start, int max_vol, vector<string>& stuffs);
int packing(int start, int max_vol);
int main() {
	int C;
	cin >> C;
	for (int test_case = 0; test_case < C; ++test_case) {
		cin >> N >> W;


		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j < 1001; ++j) {
				cache[i][j] = -1;
			}
		}
		stuffs.clear();

		for (int i = 0; i < N; ++i) {
			cin >> name[i] >> volume[i] >> urgency[i];
		}
		
		cout << packing(0, W) << " ";
		get_stuffs(0, W, stuffs);
		
		cout << stuffs.size() << endl;
		for (int i = 0; i < stuffs.size(); ++i)
			cout << stuffs[i] << endl;
		
	}
}

/* Return max sum of urgency of items after 'start' index and capacity is available to 'max_vol*/
int packing(int start, int max_vol) {
	if (start ==  N || max_vol <= 0) return 0;

	int& ret = cache[start][max_vol];
	if (ret != -1) return ret;

	// 'start' item is not included in carrier.
	ret = packing(start + 1, max_vol);
	if (volume[start] <= max_vol) {
		// If 'start' item's volume is smaller than 'max_vol', 
		// check the case that the 'start' item is included and take the maximum case.
		ret = max(ret, urgency[start] + packing(start + 1, max_vol - volume[start]));
	}
	
	return ret;
}

/* Put in 'stuffs' a list of things that can get the maximum sum of urgency. */
void get_stuffs(int start, int max_vol, vector<string>& stuffs) {
	if (start == N) return;
	
	if (packing(start, max_vol) > packing(start + 1, max_vol)) {
		// 'start' item is needed to get the answer.
		stuffs.push_back(name[start]);
		get_stuffs(start + 1, max_vol - volume[start], stuffs);
	}
	else {
		// 'start' item is not necessarily needed.
		get_stuffs(start + 1, max_vol, stuffs);
	}
}