#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>


using namespace std;

double dist[8][8];
bool visited[8];
int N;
double Answer;

void travel(int start, double totalDist);

int main() {
	int C;

	cin >> C;

	for (int test_case = 0; test_case < C; test_case++) {
		cin >> N;

		Answer = DBL_MAX;
		cout << setprecision(10) << fixed;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> dist[i][j];
			}
		}

		for (int i = 0; i < N; i++)
			travel(i, 0);
		cout << Answer << endl;
	}
}

void travel(int start, double totalDist) {
	bool allVisited = true;

	visited[start] = true;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			allVisited = false;
			travel(i, totalDist + dist[start][i]);
		}
	}
	visited[start] = false;

	if (allVisited) Answer = min(Answer, totalDist);
}