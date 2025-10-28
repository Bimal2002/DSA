// approach-1 : 
#include <bits/stdc++.h>
using namespace std;

bool isSorted(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> difficulty(n);
    for (int i = 0; i < n; i++) cin >> difficulty[i];

    int count = 0;

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            // Remove subarray [l..r]
            vector<int> remaining;
            for (int i = 0; i < l; i++) remaining.push_back(difficulty[i]);
            for (int i = r + 1; i < n; i++) remaining.push_back(difficulty[i]);

            // Check if remaining array is well-organized
            if (!remaining.empty() && isSorted(remaining))
                count++;
        }
    }

    cout << count << endl;
    return 0;
}




// Approach-2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<bool> prefixSorted(n, true), suffixSorted(n, true);

    // Compute prefix sorted info
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1])
            prefixSorted[i] = false;
        else
            prefixSorted[i] = prefixSorted[i - 1];
    }

    // Compute suffix sorted info
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1])
            suffixSorted[i] = false;
        else
            suffixSorted[i] = suffixSorted[i + 1];
    }

    int count = 0;

    // Try all subarrays [l..r] to remove
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            bool ok = true;

            bool hasLeft = (l > 0);
            bool hasRight = (r < n - 1);

            if (!hasLeft && !hasRight) continue; // remaining empty

            if (hasLeft && !prefixSorted[l - 1]) ok = false;
            if (hasRight && !suffixSorted[r + 1]) ok = false;

            if (hasLeft && hasRight && a[l - 1] > a[r + 1]) ok = false;

            if (ok) count++;
        }
    }

    cout << count << endl;
    return 0;
}
