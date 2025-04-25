// don't think just do

#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;

struct dashboard {
private:
	// mean
	double count = 0;
	int sum = 0;

	// variance
	int sumSquare = 0;

	// mode
	map<int, int> freq;
	multiset<pair<int, int>> freq_order;

	// median
	multiset<int> low, high;

public:

	void balance() {
		while (high.size() > low.size()) {
			int num = *high.begin();
			high.erase(high.find(num));
			low.insert(num);
		}

		while (low.size() > high.size() + 1) {
			int num = *low.rbegin();
			low.erase(low.find(num));
			high.insert(num);
		}
	}

	void insert(int x) {
		sum += x;
		count++;
		sumSquare += x * x;

		// mode
		if (freq_order.find({freq[x], x}) != freq_order.end()) {
			freq_order.erase({freq[x], x});
		}
		freq[x]++;
		freq_order.insert({freq[x], x});

		// median
		if (low.size() == 0) low.insert(x);
		else if (x <= (*low.rbegin())) low.insert(x);
		else high.insert(x);
		balance();
	}

	void remove(int x) {
		sum -= x;
		count--;
		sumSquare -= x * x;

		// mode
		if (freq_order.find({freq[x], x}) != freq_order.end()) {
			freq_order.erase({freq[x], x});
		}
		freq[x]--;
		if (freq[x]) freq_order.insert({freq[x], x});

		// median
		if (high.find(x) != high.end()) high.erase(high.find(x));
		else if (low.find(x) != low.end()) low.erase(low.find(x));
		balance();
	}

	double mean() {
		return sum / count;
	}

	double variance() {
		return sumSquare / count - mean() * mean();
	}

	double mode() {
		return freq_order.rbegin()->second;
	}

	double median() {
		if ((low.size() + high.size()) % 2 == 0)
			return (*low.rbegin() + (*high.begin())) / 2.0;
		else
			return *low.rbegin();
	}


};

void solve() {
	// cout << "let's get it done" << endl;
	dashboard db;
	db.insert(1);
	db.insert(2);
	db.insert(4);

	cout << db.mean() << endl;
	cout << db.median() << endl;
	cout << db.variance() << endl;
	cout << db.mode() << endl;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t = 1;
	while (t--) solve();
}