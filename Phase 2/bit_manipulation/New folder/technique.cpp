#include<bits/stdc++.h>
using namespace std;

#define lli long long int
#define endl "\n"

// void solve() {
// 	vector<int> arr  = {2, 3, 5};
// 	int n = arr.size();

// 	for (int mask = 0; mask < (1 << n); mask++) {
// 		cout << mask << ": ";
// 		for (int i = 0; i < n; i++) {
// 			if ((mask >> i) & 1) {
// 				cout << arr[i] << ", ";
// 			}
// 		}
// 		cout << endl;
// 	}
// }

// int main() {
// 	int t = 1;
// 	while (t--) {
// 		solve();
// 	}
//

// void solve() {
// 	vector<int> arr  = {2, 3, 5};
// 	int n = arr.size();

// 	for (int mask = 0; mask < (1 << n); mask++) {
// 		cout << mask << ": ";
// 		vector<int> temp;
// 		for (int i = 0; i < n; i++) {
// 			if ((mask >> i) & 1) {
// 				cout << arr[i] << ", ";
// 				temp.push_back(arr[i]);
// 			}
// 		}
// 		cout << endl;
// 		cout << endl;

// 		for (int submask = 0; submask < (1 << temp.size()); submask++) {
// 			cout << submask << ": ";
// 			for (int i = 0; i < temp.size(); i++) {
// 				if ((submask >> i) & 1) {
// 					cout << temp[i] << ", ";
// 				}
// 			}
// 			cout << endl;
// 		}

// 		cout << endl;
// 	}
// }

// int main() {
// 	int t = 1;
// 	while (t--) {
// 		solve();
// 	}
// }



void solve() {
	vector<int> arr  = {2, 3, 5};
	int n = arr.size();

	for (int mask = 0; mask < (1 << n); mask++) {
		cout << bitset<3>(mask).to_string() << endl;
		for (int submask = mask;; submask = (submask - 1)&mask) {
			cout << bitset<3>(submask).to_string() << ": ";
			for (int i = 0; i < n; i++) {
				if ((submask >> i) & 1) {
					cout << arr[i] << ", ";
				}
			}
			cout << endl;

			if (submask == 0) break;
		}
		cout << endl;
	}
}

int main() {
	int t = 1;
	while (t--) {
		solve();
	}
}