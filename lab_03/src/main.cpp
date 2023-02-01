#include <iostream>
#include "../inc/algs.hpp"
#include "../inc/time.hpp"
#include <cinttypes>
#include <fstream>
#include <string>

static void PrintVect(vector<int> a)
{
    for (int k:a)
        cout << k << " ";
    cout << endl;
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
                cout << "Input array lenght:";
                int n;
                cin >> n;

                cout << "Input array:";
                int num;
                vector<int> arr;
                while (n > 0)
                {
                    cin >> num;
                    arr.push_back(num);
                    n--;
                }
                cout << "Initial vector" << endl;
                PrintVect(arr);

                vector<int> a_1 = arr;
                vector<int> a_2 = arr;
                vector<int> a_3 = arr;

                cout << "Smooth Sort" << endl;
                SmoothSort(a_1);
                PrintVect(a_1);

                cout << "Comb Sort" << endl;
                CombSort(a_2);
                PrintVect(a_2);

                cout << "Merge Sort" << endl;
                MergeSort(a_3);
                PrintVect(a_3);
                break;
            }
        case 2:
            {
                vector<vector<int>> tests_luch;
                vector<int> tmp_1;
                for(int i = 1; i < 2; i++)
                {
                    tmp_1.push_back(i);
                }
                tests_luch.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 1; i < 11; i++)
                {
                    tmp_1.push_back(i);
                }
                tests_luch.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 1; i < 51; i++)
                {
                    tmp_1.push_back(i);
                }
                tests_luch.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 1; i < 101; i++)
                {
                    tmp_1.push_back(i);
                }
                tests_luch.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 1; i < 251; i++)
                {
                    tmp_1.push_back(i);
                }
                tests_luch.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 1; i < 501; i++)
                {
                    tmp_1.push_back(i);
                }
                tests_luch.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 1; i < 1001; i++)
                {
                    tmp_1.push_back(i);
                }
                tests_luch.push_back(tmp_1);
                int64_t start = 0, end = 0;
                ofstream fout;
                fout.open("Luch.txt");
                for (size_t j = 0; j < tests_luch.size(); j++)
                {
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<int> a_1 = tests_luch[j];
                        start+=tick();
                        SmoothSort(a_1);
                        end+=tick();
                    }

                    double g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << to_string(g) << " ";
                    start = 0;
                    end = 0;
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<int> a_1 = tests_luch[j];
                        start+=tick();
                        CombSort(a_1);
                        end+=tick();
                    }
                    g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << to_string(g) << " ";
                    start = 0;
                    end = 0;
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<int> a_1 = tests_luch[j];
                        start+=tick();
                        MergeSort(a_1);
                        end+=tick();
                    }
                    g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << to_string(g) << endl;
                    start = 0;
                    end = 0;
                }
                fout.close();

                vector<vector<int>> tests_hud;
                tmp_1.clear();
                for(int i = 1; i > 0; i--)
                {
                    tmp_1.push_back(i);
                }
                tests_hud.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 10; i > 0; i--)
                {
                    tmp_1.push_back(i);
                }
                tests_hud.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 50; i > 0; i--)
                {
                    tmp_1.push_back(i);
                }
                tests_hud.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 100; i > 0; i--)
                {
                    tmp_1.push_back(i);
                }
                tests_hud.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 250; i > 0; i--)
                {
                    tmp_1.push_back(i);
                }
                tests_hud.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 500; i > 0; i--)
                {
                    tmp_1.push_back(i);
                }
                tests_hud.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 1000; i > 0; i--)
                {
                    tmp_1.push_back(i);
                }
                tests_hud.push_back(tmp_1);
                start = 0, end = 0;
                fout.open("Hud.txt");
                for (size_t j = 0; j < tests_hud.size(); j++)
                {
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<int> a_1 = tests_hud[j];
                        start+=tick();
                        SmoothSort(a_1);
                        end+=tick();
                    }

                    double g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << to_string(g) << " ";
                    start = 0;
                    end = 0;
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<int> a_1 = tests_hud[j];
                        start+=tick();
                        CombSort(a_1);
                        end+=tick();
                    }
                    g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << to_string(g) << " ";
                    start = 0;
                    end = 0;
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<int> a_1 = tests_hud[j];
                        start+=tick();
                        MergeSort(a_1);
                        end+=tick();
                    }
                    g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << to_string(g) << endl;
                    start = 0;
                    end = 0;
                }
                fout.close();
                vector<vector<int>> tests_pr;
                tmp_1.clear();
                for(int i = 1; i < 2; i++)
                {
                    tmp_1.push_back(1 + std::rand()/((RAND_MAX + 1u)/250));
                }
                tests_pr.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 1; i < 11; i++)
                {
                    tmp_1.push_back(1 + std::rand()/((RAND_MAX + 1u)/250));
                }
                tests_pr.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 1; i < 51; i++)
                {
                    tmp_1.push_back(1 + std::rand()/((RAND_MAX + 1u)/250));
                }
                tests_pr.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 1; i < 101; i++)
                {
                    tmp_1.push_back(1 + std::rand()/((RAND_MAX + 1u)/250));
                }
                tests_pr.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 1; i < 251; i++)
                {
                    tmp_1.push_back(1 + std::rand()/((RAND_MAX + 1u)/250));
                }
                tests_pr.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 1; i < 501; i++)
                {
                    tmp_1.push_back(1 + std::rand()/((RAND_MAX + 1u)/250));
                }
                tests_pr.push_back(tmp_1);
                tmp_1.clear();
                for(int i = 1; i < 1001; i++)
                {
                    tmp_1.push_back(1 + std::rand()/((RAND_MAX + 1u)/250));
                }
                tests_pr.push_back(tmp_1);
                start = 0, end = 0;
                fout.open("Proizv.txt");
                for (size_t j = 0; j < tests_pr.size(); j++)
                {
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<int> a_1 = tests_pr[j];
                        start+=tick();
                        SmoothSort(a_1);
                        end+=tick();
                    }

                    double g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << to_string(g) << " ";
                    start = 0;
                    end = 0;
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<int> a_1 = tests_pr[j];
                        start+=tick();
                        CombSort(a_1);
                        end+=tick();
                    }
                    g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << to_string(g) << " ";
                    start = 0;
                    end = 0;
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<int> a_1 = tests_pr[j];
                        start+=tick();
                        MergeSort(a_1);
                        end+=tick();
                    }
                    g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << to_string(g) << endl;
                    start = 0;
                    end = 0;
                }
                fout.close();
                system("graphics.py");
                break;
            }
        case 0:
            {
                k = 0;
                break;
            }
        default:
            break;
        }

    }
    return 0;
}