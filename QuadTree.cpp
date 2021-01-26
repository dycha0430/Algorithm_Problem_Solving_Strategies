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

	/* quadTree의 첫번째 요소가 'b' 또는 'w' 라면 
	 * 해당 문자를 출력하고 종료한다. (기저사례)
	 */
	cout << *iter;
	if (*iter == 'x') {
		iter++;
		/* quadTree의 첫번째 요소가 x라면  해당 쿼드트리를
		 * 왼쪽 위/아래, 오른쪽 위/아래의 네 부분으로 나눈다.
		 */
		for (int i = 0; i < 4; i++) {
			start = iter;
			if (*iter == 'x') readFour(iter);
			
			iter++;
			fracs[i].assign(start, iter);
		}
		
		/* 해당 쿼드 트리를 상하로 뒤집은 결과를 얻고자하므로
		 * 왼쪽 아래, 오른쪽 아래, 왼쪽 위, 오른쪽 위 순으로
		 * 해당 함수를 재귀 호출한다.
		 */
		solve(fracs[2]);
		solve(fracs[3]);
		solve(fracs[0]);
		solve(fracs[1]);
	}

	return;
}

/* Quad Tree의 네개의 큰 부분을 압축한 결과만큼을 건너뛴다. */
void readFour(string::iterator& iter) {
	
	for (int i = 0; i < 4; i++) {
		iter++;
		if (*iter == 'x') {
			readFour(iter);
		}
	}
}