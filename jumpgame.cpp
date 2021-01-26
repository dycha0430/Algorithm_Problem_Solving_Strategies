#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int board[100][100];
int canReach[100][100];

int playGame(int n, int i, int j);
int main() {
	int C, n;
	
	cin >> C;
	for (int test_case = 0; test_case < C; test_case++) {
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			memset(canReach[i], -1, n * sizeof(int));
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}

		if (playGame(n, 0, 0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

/* n*n 게임판의 (i, j) 칸에서 jump game의 규칙을 따라 이동할 때,
 * 끝지점에 도달할 수 있다면 1, 아니라면 0을 리턴한다.
 */

int playGame(int n, int i, int j) {	
	/* 끝지점에 도달한 경우 */
	if (i == n - 1 && j == n - 1) return 1;
	/* 주어진 좌표가 게임판의 범위를 넘어간 경우 */
	else if (i >= n || j >= n) return 0;
	
	/* 메모이제이션을 통해 이미 계산된 값인 경우 */
	if (canReach[i][j] != -1) return canReach[i][j];

	int moveI = i + board[i][j], moveJ = j + board[i][j];
	
	/* 오른쪽 혹은 아래로 점프했을 때, 어느 한 경우라도
	 * 끝지점에 도달할 수 있다면 1을 리턴한다. 
	 */
	if (playGame(n, moveI, j) || playGame(n, i, moveJ)) {
		return canReach[i][j] = 1;
	}
	/* 두 경우 모두 끝지점에 도달할 수 없다며 0을 리턴. */
	return canReach[i][j] = 0;
}