#include <iostream>
#include <vector>
#include <map>
using namespace std;

short getMSBIndex(int num) {
	num >>= 1; // so that if num is 1 or 0 still its msb is 0;
	short count = 0;

	while (num) {
		count++;
		num >>= 1;
	}

	return count;
}

void countPair(vector<int>& nums, int& size) {
	map<short, int> msbCount;

	for (int i = 0; i < size; i++) {
		msbCount[getMSBIndex(nums[i])]++;
	}

	long long count = 0;
	for (auto& pair : msbCount) {
		// number of combinations to choose two elements out of n
		count += (static_cast<long long>(pair.second) * (pair.second - 1)) / 2;
	}

	cout << count << endl;
}

void solution() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		countPair(a, n);
	}
}

int main() {
	solution();
}