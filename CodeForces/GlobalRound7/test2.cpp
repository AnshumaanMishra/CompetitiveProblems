#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        vector<int> p(n);
        
        // Constructing the permutation
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                // Assign largest available for even indices
                p[i] = (n - (i / 2));
            } else {
                // Assign smallest available for odd indices
                p[i] = (i / 2) + 1;
            }
        }

        // Output the permutation

        // Compute k
        long long k = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                k |= p[i]; // OR for even i (1-based)
            } else {
                k &= p[i]; // AND for odd i (1-based)
            }
        }

        cout << k << endl;
        for (int value : p) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
