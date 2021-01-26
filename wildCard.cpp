#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare_name(string wildCard, string file);
int main() {
	int C, N;
	string wildCard, file;
	vector<string> Answer;
	cin >> C;
	
	for (int test_case = 0; test_case < C; test_case++) {
		cin >> wildCard;
		cin >> N;
		Answer.clear();
		for (int i = 0; i < N; i++) {
			cin >> file;
			if (compare_name(wildCard, file)) {
				Answer.push_back(file);
			}
		}
		
		/* Sort the list of possible answers. */
		std::sort(Answer.begin(), Answer.end());
		
		vector<string>::iterator it;
		for (it = Answer.begin(); it != Answer.end(); it++) {
			cout << *it << endl;
		}
	}
}

/* Determine if the filename `file` can be matched to the `wildCard` */
bool compare_name(string wildCard, string file) {
	int fileIndex = 0, cardIndex = 0;
	bool isMatch = true;
	while (cardIndex < wildCard.length() || fileIndex < file.length()) {
		/* If there is '*', it can match any length of string of file after fileIndex. 
		 * Match '*' with all possible file string after fileIndex.
		 * If at least one of them is matching, return true. 
		 * All of them is not maching, return false.
		 */
		if (wildCard[cardIndex] == '*') {
			for (int j = fileIndex; j <= file.length(); j++) {
				if (compare_name(wildCard.substr(cardIndex + 1), file.substr(j))) {
					return true;
				}
			}
			
			return false;
		}
		/* If wild card's character is '?', move to the next character. 
		 * If chracter is neither '*' nor '?', check whether the two character is same.
		 */
		else if (wildCard[cardIndex] != '?') {
			if (wildCard[cardIndex] != file[fileIndex]) {
				isMatch = false;
				break;
			}
		}
		fileIndex++;
		cardIndex++;
	}

	/* If wild card is all traversed, but file still contains characters,
	 * always cannot match.
	 */
	if (cardIndex == wildCard.length() && fileIndex < file.length()) {
		isMatch = false;
	}
	/* If file is all traversed, but wild card still contains characters, 
	 * they can match only when all remaining characters are '*'.
	 */
	else if (cardIndex < wildCard.length() && fileIndex == file.length()) {
		for (int i = cardIndex; i < wildCard.length(); i++) {
			if (wildCard[i] != '*') isMatch = false;
		}
	}
	return isMatch;
}