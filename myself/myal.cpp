#include "myal.h"

#include <iostream>
#include <algorithm>

using namespace std;

int binarysearch(int k, std::vector<int> &a)
{
    int start = 0;
    int end = a.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;
        if(a[mid] < k)
            start = mid + 1;
        else if (a[mid] > k)
            end = mid - 1;
        else
            return mid;
    }
    return -1;
}

int binomial(int N, int k,int& count, double p)
{
    count++;
    if (N == 0 && k == 0)
        return count;
    if (N < 0 || k < 0)
        return count;
    return (1.0 - p)*binomial(N-1, k,count, p) + p*binomial(N-1, k-1, count, p);
}

void myprint(std::vector<int> &a)
{
    for(int num : a)
        cout<<num<<",";
    cout<<"end"<<endl;
}

void select_sort(std::vector<int> &a)
{
    int minidx = -1;
    for(int i = 0; i < a.size(); ++i)
    {
        minidx = i;
        for(int j = 0; j < a.size(); ++j)
        {
            if(a[minidx] < a[j])
                minidx = j;
        }
        swap(a[i],a[minidx]);
    }
    myprint(a);
}

void insert_sort(std::vector<int> &a)
{
    for(int i = 1; i < a.size(); ++ i)
    {
        for(int j = i; j > 0 && a[j] > a[j-1]; --j)
        {
            swap(a[j],a[j-1]);
        }
    }
    myprint(a);
}
