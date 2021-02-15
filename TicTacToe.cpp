#include <iostream>

using namespace std;

const int SIZE = 3;

int whoWin(char turn, char board[3][3]);
const int win_x[8][3] = { {0, 0, 0} ,{1, 1, 1} ,{2, 2, 2} ,{0, 1, 2} ,{0, 1, 2} ,{0, 1, 2} ,{0, 1, 2} ,{0, 1, 2} };
const int win_y[8][3] = { {0, 1, 2} ,{0, 1, 2} ,{0, 1, 2} ,{0, 0, 0} ,{1, 1, 1} ,{2, 2, 2} ,{0, 1, 2} ,{2, 1, 0} };
int main() {
	int C;
	cin >> C;
	
	char board[SIZE][SIZE];
	for (int test_case = 0; test_case < C; ++test_case) {
		int turn = 0;
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				cin >> board[i][j];
				if (board[i][j] != '.') turn++;
			}
		}
		
		int ret = whoWin(turn % 2 ? 'o' : 'x', board);
		if (ret == 0) cout << "TIE" << endl;
		else if (ret == 1) cout << 'x' << endl;
		else if (ret == 2) cout << 'o' << endl;
	}
}

/* Return winner of tictactoe game when the progress is as 'board' 
 * and next turn is 'turn'. 
 * Return value : 0(draw), 1('x' wins), 2('o' wins).
 */
int whoWin(char turn, char board[3][3]) {
	// Check if the game is over because someone meets the winning condition.
	for (int i = 0; i < 8; ++i) {
		bool same = true;
		char pin = board[win_x[i][0]][win_y[i][0]];
		if (pin == '.') {
			continue;
		}
		for (int j = 1; j < 3; ++j) {
			if (pin != board[win_x[i][j]][win_y[i][j]]) same = false;
		}

		if (same) return pin == 'x' ? 1 : 2;
	}

	// Try to place the letter in all possible places.
	int result[3] = { 0, 0, 0 };
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (board[i][j] == '.') {
				board[i][j] = turn;
				result[whoWin(turn == 'x' ? 'o' : 'x', board)]++;
				board[i][j] = '.';
			}
		}
	}

	int my_num = turn == 'x' ? 1 : 2;
	int your_num = turn == 'x' ? 2 : 1;

	// If there is any place where 'turn' will alwyas win, winner is 'turn'
	if (result[my_num] != 0) return my_num;
	// Else if there is any place where they can draw, 'turn' will pick that place, and result will be draw.
	else if (result[0] != 0) return 0;
	// Else if the opponent always wins in all places, winner is the opponent.
	else if (result[your_num] != 0) return your_num;
	// The game board is full, but no one satisfies the winning condition.
	else return 0;
}