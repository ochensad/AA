#include "algs.h"
#include <iostream>

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

static int DamLev_RecNode(string src, size_t s_len, string trg, size_t t_len)
{
    if (s_len * t_len == 0)
        return max(s_len, t_len);
    
    int cost = src[s_len - 1] == trg[t_len - 1] ? 0 : 1;

    int D = DamLev_RecNode(src, s_len - 1, trg, t_len) + 1;
    int I = DamLev_RecNode(src, s_len, trg, t_len - 1) + 1;
    int S = DamLev_RecNode(src, s_len - 1, trg, t_len - 1) + cost;

    int min_way = CheckMin(D, I, S);

    if (s_len > 1 && t_len > 1 && src[s_len - 1] == trg[t_len - 2] && src[s_len - 2] == trg[t_len - 1])
        min_way = min(min_way, DamLev_RecNode(src, s_len - 2, trg, t_len - 2) + 1);
    return min_way;
}

int DamLev_Recursion(string src, string trg)
{
    return DamLev_RecNode(src, src.length(), trg, trg.length());
}

static int DamLev_RecNodeWithCache(string src, size_t s_len, string trg, size_t t_len, vector<vector<int>> &matrix)
{
    if (s_len * t_len == 0)
    {
        int res = max(s_len, t_len);
        matrix[s_len][t_len] = res;
        return max(s_len, t_len);
    }
    
    int cost = src[s_len - 1] == trg[t_len - 1] ? 0 : 1;

    int D = INT_MAX;
    if (matrix[s_len - 1][t_len] == INT_MAX)
    {
        D = (DamLev_RecNodeWithCache(src, s_len - 1, trg, t_len, matrix) + 1);
    }
    else
        D = matrix[s_len - 1][t_len] + 1;
    
    int I = INT_MAX;
    if (matrix[s_len][t_len - 1] == INT_MAX)
    {
        I = (DamLev_RecNodeWithCache(src, s_len, trg, t_len - 1, matrix) + 1);
    }
    else
        I = matrix[s_len][t_len - 1] + 1;

    int S = INT_MAX;
    if (matrix[s_len - 1][t_len - 1] == INT_MAX)
    {
        S = (DamLev_RecNodeWithCache(src, s_len - 1, trg, t_len - 1, matrix) + cost);
    }
    else
        S = matrix[s_len - 1][t_len - 1] + cost;
    
    int min_way = CheckMin(D, I, S);

    if (s_len > 1 && t_len > 1 && src[s_len - 1] == trg[t_len - 2] && src[s_len - 2] == trg[t_len - 1])
    {
        int X = INT_MAX;
        if (matrix[s_len - 2][t_len - 2] == INT_MAX)
        {
            X = DamLev_RecNodeWithCache(src, s_len - 2, trg, t_len - 2, matrix) + 1;
        }
        else
            X = matrix[s_len - 2][t_len - 2] + 1;
        min_way = min(min_way, X);
    }
    if (matrix[s_len][t_len] == INT_MAX || min_way < matrix[s_len][t_len])
        matrix[s_len][t_len] = min_way;
    return min_way;
}

int DamLev_RecursionWithCache(string src, string trg)
{
    size_t N = src.length() + 1;
    size_t M = trg.length() + 1;

    vector<vector<int>> matrix (N);

    for (size_t i = 0; i < N; i++)
    {
        matrix[i].resize(M);
        for (size_t j = 0; j < M; j++)
            matrix[i][j] = INT_MAX;
    }

    int res = DamLev_RecNodeWithCache(src, src.length(), trg, trg.length(), matrix);
    return res;
}

int Lev_Matrix(string src, string trg)
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
        }
    }
    return matrix[N - 1][M - 1];
}