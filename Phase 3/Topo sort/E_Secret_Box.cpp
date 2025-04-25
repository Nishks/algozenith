#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long count_placements(long long x, long long y, long long z, long long a, long long b, long long c) {
    if (a <= x && b <= y && c <= z) {
        // cout << a <<" " << b << " " << c << " ";
        long long ans =  (x - a + 1) * (y - b + 1) * (z - c + 1);
        // cout << ans << endl;
        return ans;
    }
    return 0;
}

long long max_positions_for_k_in_box(long long x, long long y, long long z, long long k) {
    long long max_positions = 0;

    for (long long a = 1; a <= cbrt(k); ++a) {
        if (k % a == 0) {
            for (long long b = 1; b <= sqrt(k / a); ++b) {
                if ((k / a) % b == 0) {
                    long long c = (k / a) / b;
                    vector<long long> dimensions = {a, b, c};
                    sort(dimensions.begin(), dimensions.end());
                    do {
                        long long first = dimensions[0];
                        long long second = dimensions[1];
                        long long third = dimensions[2];
                        long long positions = count_placements(x, y, z, first, second, third);
                        max_positions = max(max_positions, positions);
                    } while (next_permutation(dimensions.begin(), dimensions.end()));
                }
            }
        }
    }
    return max_positions;
}

void solve(){
    long long x, y, z, k;
    cin >> x >> y >> z >> k;
    long long result = max_positions_for_k_in_box(x, y, z, k);
    cout << result << endl;
}

int main() {
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
