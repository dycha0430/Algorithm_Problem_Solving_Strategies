#include <iostream>
#include <vector>

using namespace std;

void solve(string& quadTree);
void readFour(string::iterator& iter);
int main() {
	int C;
	string quadTree;

	cin >> C;
	for (int test_case = 0; test_case < C; test_case++) {
		cin >> quadTree;

		solve(quadTree);
		cout << endl;
	}
}

void solve(string& quadTree) {
	string fracs[4];
	int fracNum = 0, deep = 0;
	bool isFrac = false;
	string::iterator iter, start;
	
	iter = quadTree.begin();

	/* quadTree�� ù��° ��Ұ� 'b' �Ǵ� 'w' ��� 
	 * �ش� ���ڸ� ����ϰ� �����Ѵ�. (�������)
	 */
	cout << *iter;
	if (*iter == 'x') {
		iter++;
		/* quadTree�� ù��° ��Ұ� x���  �ش� ����Ʈ����
		 * ���� ��/�Ʒ�, ������ ��/�Ʒ��� �� �κ����� ������.
		 */
		for (int i = 0; i < 4; i++) {
			start = iter;
			if (*iter == 'x') readFour(iter);
			
			iter++;
			fracs[i].assign(start, iter);
		}
		
		/* �ش� ���� Ʈ���� ���Ϸ� ������ ����� ������ϹǷ�
		 * ���� �Ʒ�, ������ �Ʒ�, ���� ��, ������ �� ������
		 * �ش� �Լ��� ��� ȣ���Ѵ�.
		 */
		solve(fracs[2]);
		solve(fracs[3]);
		solve(fracs[0]);
		solve(fracs[1]);
	}

	return;
}

/* Quad Tree�� �װ��� ū �κ��� ������ �����ŭ�� �ǳʶڴ�. */
void readFour(string::iterator& iter) {
	
	for (int i = 0; i < 4; i++) {
		iter++;
		if (*iter == 'x') {
			readFour(iter);
		}
	}
}