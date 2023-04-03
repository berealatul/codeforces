#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> takeInput() {
	int t; cin >> t;
	int temp;
	vector<string> data(t);
	int i = 0;
	while (t--) {
		cin >> temp;
		cin >> data[i++];
	}
	return data;
}

void solution(string& s) {
	int index = -1;
	for (int i = 0; i < s.size(); i++) {
		if (!i) index = i;
		else if (s[i] <= s[index]) index = i;
	}

	s = s[index] + s.substr(0, index) + ((index + 1 < s.size()) ? s.substr(index + 1) : "");
}

int main() {
	vector<string> data = takeInput();
	for (auto& s : data) {
		solution(s);
		cout << s << endl;
	}
}