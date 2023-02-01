//
//  alg.cpp
//  lab_02
//
//  Created by macbook on 20.10.2022.
//

#include "alg.hpp"
#include <iostream>

vector<vector<int>> ClassicMultMatrix(vector<vector<int>> matr1, vector<vector<int>> matr2)
{
    vector<vector<int>> res (matr1.size());
    
    for(auto &i: res)
        i.resize(matr2[0].size());
    if (matr1[0].size() != matr2.size())
    {
        cout << "Ошибка: кол-во столбцов матрицы 1 != кол-ву строк матрицы 2" << endl;
        return res;
    }
    for (int i = 0; i < (int)matr1.size(); i++)
    {
        for (int j = 0; j < (int)matr2[0].size(); j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < (int)matr1[0].size(); k++)
            {
                res[i][j] += matr1[i][k] * matr2[k][j];
            }
        }
    }

    return res;
}

vector<vector<int>> VinogradMultMatrix(vector<vector<int>> matr1, vector<vector<int>> matr2)
{
    vector<vector<int>> res (matr1.size());
    
    for(auto &i: res)
        i.resize(matr2[0].size());
    
    if (matr1[0].size() != matr2.size())
    {
        cout << "Ошибка: кол-во столбцов матрицы 1 != кол-ву строк матрицы 2" << endl;
        return res;
    }
    vector<int> H(matr1.size());
    
    for (int i = 0; i < (int)matr1.size(); i++)
    {
        H[i] = 0;
        for (int j = 0; j < (int)matr1[0].size() / 2; j++)
        {
            H[i] = H[i] + matr1[i][j * 2] * matr1[i][j * 2 + 1];
        }
    }
    
    vector<int> V (matr2[0].size());
    
    for (int i = 0; i < (int)matr2[0].size(); i++)
    {
        V[i] = 0;
        for (int j = 0; j < (int)matr2.size() / 2; j++)
        {
            V[i] = V[i] + matr2[j * 2][i] * matr2[j * 2 + 1][i];
        }
    }
    for (int i = 0; i < (int)matr1.size(); i++)
    {
        for (int j = 0; j < (int)matr2[0].size(); j++)
        {
            res[i][j] = -H[i] - V[j];
            for (int k = 0; k < (int)matr1[0].size() / 2; k++)
            {
                res[i][j] = res[i][j] + (matr1[i][2 * k + 1] + matr2[2 * k][j]) * (matr1[i][2 * k] + matr2[2 * k + 1][j]);
            }
        }
    }

    if (matr1[0].size() % 2 == 1)
    {
        for (int i = 0; i < (int)matr1.size(); i++)
        {
            for (int j = 0; j < (int)matr2[0].size(); j++)
            {
                res[i][j] = res[i][j] + matr1[i][matr1[0].size() - 1] * matr2[matr1[0].size() - 1][j];
            }
        }
    }

    return res;
}

vector<vector<int>> VinogradOptimMultMatrix(vector<vector<int>> matr1, vector<vector<int>> matr2)
{
    vector<vector<int>> res (matr1.size());
    
    for(auto &i: res)
        i.resize(matr2[0].size());
    
    if (matr1[0].size() != matr2.size())
    {
        cout << "Ошибка: кол-во столбцов матрицы 1 != кол-ву строк матрицы 2" << endl;
        return res;
    }
    
    vector<int> H(matr1.size());
    
    
    int m1_2 = matr1[0].size()/2;
    for (int i = 0; i < (int)matr1.size(); i++)
    {
        H[i] = 0;
        for (int j = 0; j < m1_2; j++)
        {
            int j_2 = j<<1;
            H[i] += matr1[i][j_2] * matr1[i][j_2 + 1];
        }
    }
    
    vector<int> V (matr2[0].size());
    
    int m2_2 = matr2.size()/2;
    
    for (int i = 0; i < (int)matr2[0].size(); i++)
    {
        V[i] = 0;
        for (int j = 0; j < m2_2; j++)
        {
            int j_2 = j<<1;
            V[i] += matr2[j_2][i] * matr2[j_2 + 1][i];
        }
    }
    for (int i = 0; i < (int)matr1.size(); i++)
    {
        for (int j = 0; j < (int)matr2[0].size(); j++)
        {
            res[i][j] = -H[i] - V[j];
            for (int k = 0; k < (int)matr1[0].size() / 2; k++)
            {
                int k_2 = k << 1;
                res[i][j] += (matr1[i][k_2 + 1] + matr2[k_2][j]) * (matr1[i][k_2] + matr2[k_2 + 1][j]);
            }
        }
    }

    if (matr1[0].size() % 2 == 1)
    {
        for (int i = 0; i < (int)matr1.size(); i++)
        {
            for (int j = 0; j < (int)matr2[0].size(); j++)
            {
                res[i][j] += matr1[i][matr1[0].size() - 1] * matr2[matr1[0].size() - 1][j];
            }
        }
    }

    return res;
}
