#include <iostream>
#include <string>
#include <cstdint>
#include <cmath>
#include <fstream>
using namespace std;

#include "algs.h"
#include "../inc/time.h"


int main(void)
{
    int k = 1;
    while (k)
    {
        int n = 0;
        cout << "Input 1 for personal using" << endl;
        cout << "Input 2 for testing" << endl;
        cout << "Input 3 for making graphics" << endl;
        cout << "Input 0 for exit" << endl;
        cin >> n;
        switch(n)
        {
            case 1:
            {
                string s1;
                string s2;

                cout << "Source string: ";
                cin >> s1;
                cout << "Target string: ";
                cin >> s2;

                cout << endl;
                cout << "Lev Matrix: " << Lev_Matrix(s1, s2) << endl;
                cout << "Dam-Lev Matrix: " << DamLev_Matrix(s1, s2) << endl;
                cout << "Dam-Lev Recursion: " << DamLev_Recursion(s1, s2) << endl;
                cout << "Dam-Lev Recursion with cache: " << DamLev_RecursionWithCache(s1, s2) << endl;
                break;
            }
            case 2:
            {
                vector<vector<string>> tests = { { "gfg", "", "", "cympwd", "waauhui", "vvobdddd", "ujyybxkuw", "jtrezzaulu" }, { "", "", "gdmlp", "akytjq", "tefnach", "bbbpjoou", "yyqgxmsbr", "ewyqeztwbe"} };
                int64_t start = 0, end = 0;
                for (size_t j = 0; j < tests[0].size(); j++)
                {
                    cout << endl << "||" << tests[0][j] << " " << tests[1][j] << "||" << endl;
                    cout << endl << "|Lev Metrix Time|" << endl;
                    for (int i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        start += tick();
                        Lev_Matrix(tests[0][j], tests[1][j]);
                        end += tick();
                    }
                    print_result(start / NUMBER_OF_RUNS, end / NUMBER_OF_RUNS);
                    printf("Matrix - %llu byte\n\n",  tests[0][j].length() * tests[1][j].length() * sizeof(int));

                    start = 0, end = 0;

                    cout << "|Dam-Lev Metrix Time|" << endl;
                    for (int i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        start += tick();
                        DamLev_Matrix(tests[0][j], tests[1][j]);
                        end += tick();
                    }
                    print_result(start / NUMBER_OF_RUNS, end / NUMBER_OF_RUNS);
                    printf("Matrix - %llu byte\n\n",  tests[0][j].length() * tests[1][j].length() * sizeof(int));

                    start = 0, end = 0;
                    cout << "|Dam-Lev Recoursion Time|" << endl;
                    for (int i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        start += tick();
                        DamLev_Recursion(tests[0][j], tests[1][j]);
                        end += tick();
                    }
                    print_result(start / NUMBER_OF_RUNS, end / NUMBER_OF_RUNS);
                    printf("Recoursion - %llu byte\n\n",  (size_t)pow(tests[0][j].length(), tests[1][j].length()) * sizeof(int));

                    start = 0, end = 0;
                    cout << "|Dam-Lev Recoursion with cache Time|" << endl;
                    for (int i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        start += tick();
                        DamLev_RecursionWithCache(tests[0][j], tests[1][j]);
                        end += tick();
                    }
                    print_result(start / NUMBER_OF_RUNS, end / NUMBER_OF_RUNS);
                    printf("Matrix - %llu byte\n\n",  tests[0][j].length() * tests[1][j].length() * sizeof(int));
                }
                break;
            }
            case 3:
            {
                int64_t start = 0, end = 0;
                ofstream fout;
                fout.open("smallGraphic.txt");

                vector<string> test_1 = {"abvfs", "hsjhdf", "jsdhfsd", "ksjfhfvf", "jhfsskskl", "kjjssffjks"};
                vector<string> test_2 = {"abass", "haewdf", "jadefhd", "askkmdjk", "lapsieadd", "kasosdokdf"};
                start = 0, end = 0;
                for (size_t j = 0; j < test_1.size(); j++)
                {
                    start = 0, end = 0;
                    for (int i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        start += tick();
                        Lev_Matrix(test_1[j], test_2[j]);
                        end += tick();
                    }
                    double g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << std::to_string(g) << " ";

                    start = 0, end = 0;

                    for (int i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        start += tick();
                        DamLev_Matrix(test_1[j], test_2[j]);
                        end += tick();
                    }
                    g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << std::to_string(g) << endl;
                }
                fout.close();
    
                fout.open("largeGraphic.txt");

                vector<string> test_3 = {"", "h", "dj", "ksj", "kskl", "kjjss", "hdfjsd", "jdloutr", "ksbdyfrg", "msloueghr", "bsnrdolhde", "nbdlpiueght", "bdlorgtshutr"};
                vector<string> test_4 = {"", "f", "ja", "djk", "laps", "kasos", "jdfjdl", "jsjbbbr", "bsdrbdyj", "nspiyebfg", "ndlpiyebdg", "bvdnergdlpi", "nbdmlpoydbrg"};
                start = 0, end = 0;
                for (size_t j = 0; j < test_3.size(); j++)
                {
                    start = 0, end = 0;
                    for (int i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        start += tick();
                        DamLev_Recursion(test_3[j], test_4[j]);
                        end += tick();
                    }
                    double g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << std::to_string(g) << " ";

                    start = 0, end = 0;

                    for (int i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        start += tick();
                        DamLev_RecursionWithCache(test_3[j], test_4[j]);
                        end += tick();
                    }
                    g = (double)(end / NUMBER_OF_RUNS - start / NUMBER_OF_RUNS)/HZ;
                    fout << std::to_string(g) << endl;
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
        }
    }

    return 0;
}
