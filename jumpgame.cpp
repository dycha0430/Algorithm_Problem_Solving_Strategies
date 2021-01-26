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

/* n*n �������� (i, j) ĭ���� jump game�� ��Ģ�� ���� �̵��� ��,
 * �������� ������ �� �ִٸ� 1, �ƴ϶�� 0�� �����Ѵ�.
 */

int playGame(int n, int i, int j) {	
	/* �������� ������ ��� */
	if (i == n - 1 && j == n - 1) return 1;
	/* �־��� ��ǥ�� �������� ������ �Ѿ ��� */
	else if (i >= n || j >= n) return 0;
	
	/* �޸������̼��� ���� �̹� ���� ���� ��� */
	if (canReach[i][j] != -1) return canReach[i][j];

	int moveI = i + board[i][j], moveJ = j + board[i][j];
	
	/* ������ Ȥ�� �Ʒ��� �������� ��, ��� �� ����
	 * �������� ������ �� �ִٸ� 1�� �����Ѵ�. 
	 */
	if (playGame(n, moveI, j) || playGame(n, i, moveJ)) {
		return canReach[i][j] = 1;
	}
	/* �� ��� ��� �������� ������ �� ���ٸ� 0�� ����. */
	return canReach[i][j] = 0;
}