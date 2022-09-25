#include "../inc/algs.h"

static int CheckMin(int n1, int n2, int n3)
{
    return (n1 = n1 < n2 ? n1 : n2) < n3 ? n1 : n3;
}

int DamLev_Matrix(string src, string trg)
{
    if (src.length() * trg.length() == 0)
    {
        return max(trg.length(), src.length());
    }

    size_t N = src.length() + 1;
    size_t M = trg.length() + 1;

    vector<vector<int>> matrix (N);

    for (size_t i = 0; i < N; i++)
        matrix[i].resize(M);

    for (size_t i = 0; i < N; i++)
        matrix[i][0] = i;
    
    for (size_t j = 0; j < M; j++)
        matrix[0][j] = j;
    
    for (size_t i = 1; i < N; i++)
    {
        for (size_t j = 1; j < M; j++)
        {
            int cost = src[i - 1] == trg[j - 1] ? 0 : 1;
            matrix[i][j] = CheckMin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);

            if (i > 1 && j > 1 && src[i - 1] == trg[j - 2] && src[i - 2] == trg[j - 1])
                matrix[i][j] = min(matrix[i][j], matrix[i - 2][j - 2] + cost);
        }
    }
    return matrix[N - 1][M - 1];
}
