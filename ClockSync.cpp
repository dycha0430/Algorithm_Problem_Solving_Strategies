#include <iostream>
#include <algorithm>
#include <vector>

#define SWITCH_NUM 10

using namespace std;

const int conn[SWITCH_NUM][16] = {
	{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
	{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
	{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};

int clock_time[16];
int clickSwitch(int num, int click_num);

int main() {
	int C;
	cin >> C;
	
	for (int test_case = 0; test_case < C; test_case++) {
		for (int i = 0; i < 16; i++) {
			cin >> clock_time[i];
			clock_time[i] %= 12;
		}

		cout << clickSwitch(0, 0) << endl;
	}
}

int clickSwitch(int num, int click_num) {
	if (num >= SWITCH_NUM) {
		bool ok = true;
		for (int i = 0; i < 16; i++) {
			if (clock_time[i] != 0) ok = false;
		}
		
		if (ok) {
			return click_num;
		}
		else return -1;
	}
	
	int ret, ans = 40;
	bool impossible = true;
	for (int i = 0; i < 4; i++) {
		int tmp[16];
		copy(clock_time, clock_time + 16, tmp);
		
		for (int j = 0; j < 16; j++) {
			clock_time[j] += (conn[num][j] * 3 * i);
			clock_time[j] %= 12;
		}

		ret = clickSwitch(num + 1, click_num + i);
		if (ret != -1) {
			ans = min(ans, ret);
			impossible = false;
		}

		copy(tmp, tmp + 16, clock_time);
	}

	if (impossible) return -1;
	return ans;
}