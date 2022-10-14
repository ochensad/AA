#include <iostream>
#include "../inc/algs.hpp"
#include "../inc/time.hpp"
#include <cinttypes>

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
        cout << "Input 2 for testing" << endl;
        cout << "Input 3 for having graphics" << endl;
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
                vector<vector<int>> tests ={
                    {1,2,3,4,5,6,6,7,8},
                    {9,8,7,6,5,4,3,2,1},
                    {3,7,2,3,4,5,9,1,2,0},
                    {1,1,1,1,1,1,5,5,5,5,5},
                    {9,3,0,2,6,4,2,7,4,1,0,5,8,3,5,4},
                    {1},
                    {},
                    {1,3,2},
                    {9,1,2,4,2,0,0,0,8,5,5,8}
                };
                int64_t start = 0, end = 0;
                for (size_t j = 0; j < tests.size(); j++)
                {
                    cout << "Test " << j + 1<< " : ";

                    cout << "Smooth Sort" << endl;
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<int> a_1 = tests[j];
                        cout << "Smooth Sort" << endl;
                        start+=tick();
                        SmoothSort(a_1);
                        end+=tick();
                    }
                    print_result(start / NUMBER_OF_RUNS, end / NUMBER_OF_RUNS);
                    printf("Sort -  byte\n\n");

                    cout << "Comb Sort" << endl;
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<int> a_1 = tests[j];
                        cout << "Smooth Sort" << endl;
                        start+=tick();
                        CombSort(a_1);
                        end+=tick();
                    }
                    print_result(start / NUMBER_OF_RUNS, end / NUMBER_OF_RUNS);
                    printf("Sort -  byte\n\n");

                    cout << "Merge Sort" << endl;
                    for(size_t i = 0; i < NUMBER_OF_RUNS; i++)
                    {
                        vector<int> a_1 = tests[j];
                        cout << "Smooth Sort" << endl;
                        start+=tick();
                        MergeSort(a_1);
                        end+=tick();
                    }
                    print_result(start / NUMBER_OF_RUNS, end / NUMBER_OF_RUNS);
                    printf("Sort -  byte\n\n");
                }
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