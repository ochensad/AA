//
//  main.cpp
//  lab_02
//
//  Created by macbook on 20.10.2022.
//

#include <iostream>
#include "alg.hpp"
#include <cinttypes>
#include <vector>
#include <fstream>
#include <string>
#include "../inc/time.hpp"
using namespace std;

vector<vector<int>> CreateTest(int n)
{
    vector<vector<int>> tests;
    for(int j = 0; j < n; j++)
    {
        vector<int> tmp_1;
        for(int i = 0; i < n; i++)
        {
            tmp_1.push_back(1 + std::rand()/((RAND_MAX + 1u)/10));
        }
        tests.push_back(tmp_1);
    }
    return tests;
}

static void PrintMatrix(vector<vector<int>> a)
{
    for (auto k:a)
    {
        for(auto l: k)
            cout << l << " ";
        cout << endl;
    }
}

static void InputMatrix(vector<vector<int>> &mat)
{
    cout << "Input matrix size like N M:";
    int n, m;
    cin >> n >> m;
    
    cout << "Input matrix:" << endl;
    int num;
    vector<vector<int>> matrix (n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> num;
            matrix[i].push_back(num);
            //cout << " ";
        }
        //cout << endl;
    }
    mat = matrix;
}

int main(void)
{
    int k = 1;
    while (k)
    {
        cout << "Input 1 for personal using" << endl;
        cout << "Input 2 for having graphics" << endl;
        cout << "Input 0 for exit" << endl;
        int choise = 0;
        cin >> choise;
        switch (choise)
        {
            case 1:
            {
                vector<vector<int>> matrix_1;
                InputMatrix(matrix_1);
                
                cout << "Initial matrix #1" << endl;
                PrintMatrix(matrix_1);
                
                vector<vector<int>> matrix_2;
                InputMatrix(matrix_2);
                
                cout << "Initial matrix #2" << endl;
                PrintMatrix(matrix_2);
                
                cout << "Classic Mult Matrix" << endl;
                
                vector<vector<int>> res = ClassicMultMatrix(matrix_1, matrix_2);
                PrintMatrix(res);
                cout << "Vinograd Mult Matrix" << endl;
                res = VinogradMultMatrix(matrix_1, matrix_2);
                PrintMatrix(res);
                cout << "Vinograd Optimazed Mult Matrix" << endl;
                res = VinogradOptimMultMatrix(matrix_1, matrix_2);
                PrintMatrix(res);
                break;
            }
            case 2:
            {
                int64_t start = 0, end = 0;
                ofstream fout;
                fout.open("Odd.txt");
                for (size_t j = 1; j < 6; j+=2)
                {
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<vector<int>> m_1 = CreateTest(j*100);
                        vector<vector<int>> m_2 = CreateTest(j*100);
                        start+=tick();
                        ClassicMultMatrix(m_1, m_2);
                        end+=tick();
                    }

                    double g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << to_string(g) << " ";
                    start = 0;
                    end = 0;
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<vector<int>> m_1 = CreateTest(j*100);
                        vector<vector<int>> m_2 = CreateTest(j*100);
                        start+=tick();
                        VinogradMultMatrix(m_1, m_2);
                        end+=tick();
                    }
                    g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << to_string(g) << " ";
                    start = 0;
                    end = 0;
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<vector<int>> m_1 = CreateTest(j*100);
                        vector<vector<int>> m_2 = CreateTest(j*100);
                        start+=tick();
                        VinogradOptimMultMatrix(m_1, m_2);
                        end+=tick();
                    }
                    g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << to_string(g) << endl;
                    start = 0;
                    end = 0;
                }
                fout.close();
                start = 0, end = 0;
                fout.open("Even.txt");
                for (size_t j = 2; j <= 6; j+=2)
                {
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<vector<int>> m_1 = CreateTest(j*100);
                        vector<vector<int>> m_2 = CreateTest(j*100);
                        start+=tick();
                        ClassicMultMatrix(m_1, m_2);
                        end+=tick();
                    }

                    double g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << to_string(g) << " ";
                    start = 0;
                    end = 0;
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<vector<int>> m_1 = CreateTest(j*100);
                        vector<vector<int>> m_2 = CreateTest(j*100);
                        start+=tick();
                        VinogradMultMatrix(m_1, m_2);
                        end+=tick();
                    }
                    g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << to_string(g) << " ";
                    start = 0;
                    end = 0;
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<vector<int>> m_1 = CreateTest(j*100);
                        vector<vector<int>> m_2 = CreateTest(j*100);
                        start+=tick();
                        VinogradOptimMultMatrix(m_1, m_2);
                        end+=tick();
                    }
                    g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << to_string(g) << endl;
                    start = 0;
                    end = 0;
                }
                fout.close();
                break;
            }
            case 0:
                k = 0;
                break;
            default:
                break;
        }
    }
    return 0;
}
