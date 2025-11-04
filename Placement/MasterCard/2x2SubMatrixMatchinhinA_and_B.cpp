#include <bits/stdc++.h>
using namespace std;
void flip2x2(vector<string> &mat, int r, int c)
{
    for (int i = r; i <= r + 1; i++)
    {
        for (int j = c; j <= c + 1; j++)
        {
            mat[i][j] = (mat[i][j] == '0') ? '1' : '0';
        }
    }
}
string canTransform(vector<string> &A, vector<string> &B, int N, int M)
{
    if (N < 2 || M < 2)
    {
        return (A == B) ? "YES" : "NO";
    }

    vector<string> temp = A;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (temp[i][j] != B[i][j])
            {
                if (i < N - 1 && j < M - 1)
                {
                    flip2x2(temp, i, j);
                }
                else
                {
                    return "NO";
                }
            }
        }
    }
    return "YES";
}

int main()
{
    int N, M;
    cin >> N >> M;
    // cin>>M;
    // if(!(cin>>M)){
    //     M= N;
    // }
    vector<string> A(N), B(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    string result = canTransform(A, B, N, M);
    cout << result << endl;
}