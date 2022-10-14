#include "../inc/algs.hpp"
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

static vector<int> CountLeoNums(int len)
{
    int a = 1, b = 1;
    int tmp = 0;
    vector<int> nums;
    while(a <= len)
    {
        nums.push_back(a);
        tmp = a;
        a = b;
        b = tmp + b + 1;
    }
    return nums;
}

static void GetChild(int i, int k, vector<int> nums, int &t_r, int &t_l, int &k_r, int &k_l)
{
    t_r = i-1;
    k_r = k-2;
    t_l = t_r - nums[k_r];
    k_l = k - 1;
}

static void RestoreHeap(vector<int> &list, int i, vector<int> &heap, vector<int> &nums)
{
    int cur = heap.size() - 1;
    int k = heap[cur];
    int j = 0;
    int tmp = 0;
    while (cur > 0)
    {
        j = i - nums[k];
        if ((list[j] > list[i]) && (k < 2 || (list[j] > list[i-1] && list[j] > list[i-2])))
        {
            tmp = list[i];
            list[i] = list[j];
            list[j] = tmp;
            i = j;
            cur--;
            k = heap[cur];
        }
        else
            break;
    }

    while (k>=2)
    {
        int t_right, t_left, k_right, k_left;
        GetChild(i, k, nums, t_right, t_left, k_right,k_left);
        if (list[i] < list[t_right] || list[i] < list[t_left])
        {
            if (list[t_right] > list[t_left])
            {
                tmp = list[i];
                list[i] = list[t_right];
                list[t_right] = tmp;
                i = t_right;
                k = k_right;
            }
            else
            {
                tmp = list[i];
                list[i] = list[t_left];
                list[t_left] = tmp;
                i = t_left;
                k = k_left;
            }
        }
        else
            break;
    }
}

void SmoothSort(vector<int> &list)
{
    vector<int> l_nums = CountLeoNums(list.size());

    vector<int> heap;
    for (int i = 0; i < (int)list.size(); i++)
    {
        if (heap.size() >=2 && heap[heap.size() - 2] == heap[heap.size() - 1] + 1)
        {
            heap.pop_back();
            heap[heap.size() - 1] += 1; 
        }
        else
        {
            if (heap.size() >= 1 && heap[heap.size() - 1] == 1)
                heap.push_back(0);
            else
                heap.push_back(1);
        }

        RestoreHeap(list, i, heap, l_nums);

    }

    int k;
    for (int i = list.size() - 1; i >= 0; i--)
    {
        if (heap[heap.size() - 1] < 2)
            heap.pop_back();
        else
        {
            k = heap[heap.size() - 1];
            heap.pop_back();
            int t_right, t_left, k_right, k_left;
            GetChild(i, k, l_nums, t_right, t_left, k_right,k_left);
            heap.push_back(k_left);
            RestoreHeap(list, t_left, heap, l_nums);
            heap.push_back(k_right);
            RestoreHeap(list, t_right, heap, l_nums);
        }
    }
}

void CombSort(vector<int> &list)
{
    const double factor = 1.247;
    double gapFactor = list.size() / factor;
    int gap = 0;
    while (gapFactor > 1)
    {
        gap = round(gapFactor);

        for(int i = 0, j = gap;j < (int)list.size(); i++, j++)
        {
            if (list[i] > list[j])
            {
                int tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
        gapFactor = gapFactor / factor;
    }
}

vector<int> MergeSort(vector<int> list)
{
    if (list.size() == 1 || list.size() == 0)
        return list;
    size_t middle = list.size()/2;

    vector<int> L;
    for(size_t i = 0; i < middle; i++)
        L.push_back(list[i]);
    vector<int> R;
    for(size_t i = middle; i < list.size() ; i++)
        R.push_back(list[i]);
    
    R = MergeSort(R);
    L = MergeSort(L);

    size_t n = 0, m = 0, k = 0;
    vector<int> C (L.size() + R.size());
    for(int &l:C)
        l = 0;
    
    while(n < L.size() && m < R.size())
    {
        if (L[n] <= R[m])
        {
            C[k] = L[n];
            n++;
        }
        else
        {
            C[k] = R[m];
            m++;
        }
        k++;
    }
    while (n < L.size())
    {
        C[k] = L[n];
        n++;
        k++;
    }
    while (m < R.size())
    {
        C[k] = R[m];
        m++;
        k++;
    }
    return C;
}