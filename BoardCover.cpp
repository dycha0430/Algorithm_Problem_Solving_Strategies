#include <cstdio>
#include <iostream>
using namespace std;

int Answer, H, W;
int board[20][20];

int placeBlock(int i, int j);

int main() {
	int C, whiteNum;
	string row;
	cin >> C;

	for (int test_case = 0; test_case < C; test_case++) {
		Answer = 0;
		whiteNum = 0;
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) board[i][j] = 0;
		}

		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			cin >> row;
			for (int j = 0; j < W; j++) {
				if (row[j] == '#') board[i][j] = 1;
				else whiteNum++;
			}
		}

		if (whiteNum % 3 == 0) {
			Answer = placeBlock(0, 0);
		}

		cout << Answer << endl;

	}
}

int placeBlock(int i, int j) {
	//cout << "(" << i << "," << j << ") " << board[i][j] << endl;
	if (i == H - 1 && j == W - 1) {
		if (board[i][j]) return 1;
		else return 0;
	}

	if (board[i][j]) {
		if (j == W - 1) return placeBlock(i + 1, 0);
		else return placeBlock(i, j + 1);
	}

	int num = 0;

	if (i + 1 < H && j > 0 && !board[i + 1][j - 1] && !board[i + 1][j]) {
		board[i][j] = board[i + 1][j - 1] = board[i + 1][j] = 1;
		if (j == W - 1) num += placeBlock(i + 1, 0);
		else num += placeBlock(i, j + 1);
		board[i][j] = board[i + 1][j - 1] = board[i + 1][j] = 0;
	}

	if (i == H - 1 || j == W - 1) return num;

	if (!board[i + 1][j] && !board[i][j + 1]) {
		board[i][j] = board[i + 1][j] = board[i][j + 1] = 1;
		num += placeBlock(i, j + 1);
		board[i][j] = board[i + 1][j] = board[i][j + 1] = 0;
	}

	if (!board[i][j + 1] && !board[i + 1][j + 1]) {
		board[i][j] = board[i + 1][j + 1] = board[i][j + 1] = 1;
		num += placeBlock(i, j + 1);
		board[i][j] = board[i + 1][j + 1] = board[i][j + 1] = 0;
	}

	if (!board[i + 1][j] && !board[i + 1][j + 1]) {
		board[i][j] = board[i + 1][j + 1] = board[i + 1][j] = 1;
		num += placeBlock(i, j + 1);
		board[i][j] = board[i + 1][j + 1] = board[i + 1][j] = 0;
	}

	return num;
}