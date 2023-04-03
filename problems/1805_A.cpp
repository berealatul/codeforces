#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<int>> takeInput() {
	vector<vector<int>> data;
	int t; cin >> t;
	int temp;

	while (t--) {
		cin >> temp;
		vector<int> buffer(temp, 0);
		int i = 0;
		while (temp--) cin >> buffer[i++];
		data.push_back(buffer);
	}

	return data;
}

int solution(vector<int>& data) {
	const int maxLimit = pow(2, 8);
	for (auto i = 0; i < maxLimit; i++) {
		int value;
		bool valueInitialized = false;
		for (auto& val : data) {
			if (!valueInitialized) {
				valueInitialized = true;
				value = (val ^ i);
			}
			else value ^= (val ^ i);
		}
		if (!value) return i;
	}
	return -1;
}

int main() {
	vector<vector<int>> data = takeInput();
	for (auto& dataset : data) {
		cout << solution(dataset) << endl;
	}
}