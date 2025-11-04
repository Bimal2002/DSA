#include <bits/stdc++.h>
using namespace std;

vector<int> finalPosition(vector<vector<int>> cards, vector<vector<int>> moves, int query) {
    // Build columns
    unordered_map<int, pair<int,int>> pos; // card -> (row, col)
    unordered_map<int, vector<int>> cols;  // col -> list of cards

    for (auto &c : cards) {
        int id = c[0], r = c[1], col = c[2];
        if ((int)cols[col].size() <= r) cols[col].resize(r + 1);
        cols[col][r] = id;
        pos[id] = {r, col};
    }

    // Process moves
    for (auto &m : moves) {
        int id = m[0];
        int oldR = m[1], oldC = m[2], newR = m[3], newC = m[4];

        // Remove from old column
        auto &src = cols[oldC];
        src.erase(src.begin() + oldR);

        // Update rows above (move up)
        for (int i = oldR; i < (int)src.size(); i++) {
            pos[src[i]] = {i, oldC};
        }

        // Insert into new column
        auto &dst = cols[newC];
        if (newR > (int)dst.size()) newR = dst.size();
        dst.insert(dst.begin() + newR, id);

        // Update all rows below (move down)
        for (int i = newR; i < (int)dst.size(); i++) {
            pos[dst[i]] = {i, newC};
        }
    }

    return {pos[query].first, pos[query].second};
}

int main() {
    vector<vector<int>> cards = {{1,1,0},{3,0,0},{6,0,1},{4,0,2},{5,2,0},{7,1,1},{2,1,2}};
    vector<vector<int>> moves = {{6,0,1,2,0},{7,0,1,0,2}};
    int query = 2;

    vector<int> ans = finalPosition(cards, moves, query);
    cout << "[" << ans[0] << "," << ans[1] << "]" << endl;  // [2,2]
}
