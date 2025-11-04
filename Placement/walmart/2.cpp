#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, N, x, y, k;
    cin >> M >> N >> x >> y >> k;

    // Case 1: No move
    if (k == 0) {
        cout << 1 << endl;
        return 0;
    }

    // Case 2: If k >= 2, bishop can cover all cells of same color
    if (k >= 2) {
        int totalCells = M * N;
        int sameColorCells = totalCells / 2 + (totalCells % 2);
        cout << sameColorCells << endl;
        return 0;
    }

    // Case 3: k == 1 -> only cells on diagonals through (x,y)
    int count = 1; // include starting cell

    // 4 diagonal directions
    int dx[] = {-1, -1, 1, 1};
    int dy[] = {-1, 1, -1, 1};

    for (int dir = 0; dir < 4; dir++) {
        int i = x + dx[dir];
        int j = y + dy[dir];
        while (i >= 1 && i <= M && j >= 1 && j <= N) {
            count++;
            i += dx[dir];
            j += dy[dir];
        }
    }

    cout << count << endl;
    return 0;
}
