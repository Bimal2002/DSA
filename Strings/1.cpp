#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

vector<string> subchain(vector<string> chain, vector<string> elements) {
    // Map to store the positions of each element in the chain
    unordered_map<string, int> posMap;
    for (int i = 0; i < chain.size(); ++i) {
        posMap[chain[i]] = i;
    }

    int start = -1, end = -1;
    int minLen = numeric_limits<int>::max();

    for (int i = 0; i < chain.size(); ++i) {
        if (chain[i] == elements[0]) {
            int k = 0;
            int j = i;
            while (j < chain.size() && k < elements.size()) {
                if (chain[j] == elements[k]) {
                    ++k;
                }
                ++j;
            }
            if (k == elements.size() && (j - i) < minLen) {
                start = i;
                end = j;
                minLen = j - i;
            }
        }
    }

    if (start == -1 || end == -1) {
        return {};
    }

    return vector<string>(chain.begin() + start, chain.begin() + end);
}

int main() {
    int chainSize, elementsSize;
    cout << "Enter the size of the chain: ";
    cin >> chainSize;
    vector<string> chain(chainSize);
    cout << "Enter the elements of the chain:\n";
    for (int i = 0; i < chainSize; ++i) {
        cin >> chain[i];
    }

    cout << "Enter the size of the elements: ";
    cin >> elementsSize;
    vector<string> elements(elementsSize);
    cout << "Enter the elements to find:\n";
    for (int i = 0; i < elementsSize; ++i) {
        cin >> elements[i];
    }

    vector<string> result = subchain(chain, elements);

    if (result.empty()) {
        cout << "No valid subchain found.\n";
    } else {
        cout << "The subchain is: ";
        for (const string& str : result) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
