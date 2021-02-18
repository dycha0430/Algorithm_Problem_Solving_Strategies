#include <iostream>
#include <algorithm>

using namespace std;
const bool WIN = true, LOSE = false;
const int WIDTH = 5;
int cache[1 << 25];
int canWin(int board);

int main() {
	int C;
	cin >> C;

	for (int i = 0; i < (1 << 25); ++i) cache[i] = -1;

	bool board[5][5];
	int parseBoard = 0;
	char input;
	for (int test_case = 0; test_case < C; ++test_case) {
		parseBoard = 0;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				cin >> input;
				if (input == '#') parseBoard |= (1 << (i * WIDTH + j));
			}
		}

		if (canWin(parseBoard)) cout << "WINNING" << endl;
		else cout << "LOSING" << endl;
	}
}

/* Return 1 if the player of this turn can win. */
int canWin(int board) {

	int& ret = cache[board];
	if (ret != -1) return ret;
	/*
	 * # #
	 * #
	 */
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (!(board & (1 << (i * WIDTH + j))) && !(board & (1 << ((i + 1) * WIDTH + j))) && !(board & (1 << (i * WIDTH + j + 1)))) {
				if (!canWin(board | (1 << (i * WIDTH + j)) | (1 << ((i + 1) * WIDTH + j)) | (1 << (i * WIDTH + j + 1)))) return ret = WIN;
			}
		}
	}

	/*
	 * #
	 * # #
	 */
	for (int i = 1; i < 5; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (!(board & (1 << (i * WIDTH + j))) && !(board & (1 << ((i - 1) * WIDTH + j))) && !(board & (1 << (i * WIDTH + j + 1)))) {
				if (!canWin(board | (1 << (i * WIDTH + j)) | (1 << ((i - 1) * WIDTH + j)) | (1 << (i * WIDTH + j + 1)))) return ret = WIN;
			}
		}
	}

	/*
	 * # #
	 *   #
	 */
	for (int i = 0; i < 4; ++i) {
		for (int j = 1; j < 5; ++j) {
			if (!(board & (1 << (i * WIDTH + j))) && !(board & (1 << ((i + 1) * WIDTH + j))) && !(board & (1 << (i * WIDTH + j - 1)))) {
				if (!canWin(board | (1 << (i * WIDTH + j)) | (1 << ((i + 1) * WIDTH + j)) | (1 << (i * WIDTH + j - 1)))) return ret = WIN;
			}
		}
	}

	/*
	 *   # 
	 * # #
	 */
	for (int i = 1; i < 5; ++i) {
		for (int j = 1; j < 5; ++j) {
			if (!(board & (1 << (i * WIDTH + j))) && !(board & (1 << ((i - 1) * WIDTH + j))) && !(board & (1 << (i * WIDTH + j - 1)))) {
				if (!canWin(board | (1 << (i * WIDTH + j)) | (1 << ((i - 1) * WIDTH + j)) | (1 << (i * WIDTH + j - 1)))) return ret = WIN;
			}
		}
	}

	/*
	 * # #
	 */
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (!(board & (1 << (i * WIDTH + j))) && !(board & (1 << (i * WIDTH + j + 1)))) {
				if (!canWin(board | (1 << (i * WIDTH + j)) | (1 << (i * WIDTH + j + 1)))) return ret = WIN;
			}
		}
	}

	/*
	 * # 
	 * #
	 */
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (!(board & (1 << (i * WIDTH + j))) && !(board & (1 << ((i + 1) * WIDTH + j)))) {
				if (!canWin(board | (1 << (i * WIDTH + j)) | (1 << ((i + 1) * WIDTH + j)))) return ret = WIN;
			}
		}
	}

	return ret = LOSE;
}