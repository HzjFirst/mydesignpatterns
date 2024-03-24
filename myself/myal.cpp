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

void merge(std::vector<int> &a, int start, int mid, int end)
{
    std::vector<int> aa(end-start+1);
    int i = start, j = mid+1, k = 0;
    while(i<=mid && j<=end)
    {
        if(a[i]<a[j])
            aa[k++] = a[i++];
        else
            aa[k++] = a[j++];
    }
    while (i<=mid) {
        aa[k++] = a[i++];
    }
    while (j<=end) {
        aa[k++] = a[j++];
    }
    k = 0;
    for(i=start; i <= end; ++i)
    {
        a[i] = aa[k++];
    }
}

void merge_exec(std::vector<int> &a,int start,int end)
{
    if(start >= end)
        return;
    int mid = (start + end) / 2;
    merge_exec(a,start,mid);
    merge_exec(a,mid+1,end);
    merge(a,start,mid,end);
}

void merge_sort(std::vector<int> &a)
{
    merge_exec(a,0,a.size()-1);
    myprint(a);
}

tuple<int,int,int> find_max_array(std::vector<int> &a, int start,int mid,int end)
{
    int max_left = -1;
    int max_right = -1;
    int left_sum = -0x3f3f3f3f  ;
    int sum = 0;
    for(int i = mid; i >= start; --i)
    {
        sum = sum + a[i];
        if(sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = -0x3f3f3f3f;
    sum = 0;
    for(int j = mid+1; j < end; ++j)
    {
        sum += a[j];
        if(sum > right_sum)
        {
            right_sum = sum;
            max_right = j;
        }
    }
    return make_tuple(max_left,max_right,left_sum+right_sum);
}


tuple<int,int,int> find_max_sub_exec(std::vector<int> &a,int start,int end)
{
    if(start == end)
        return make_tuple(start,end,a[start]);
    else
    {
        int mid = (start + end) * 0.5;
        auto left = find_max_sub_exec(a,start,mid);
        auto right = find_max_sub_exec(a,mid+1,end);
        auto cross = find_max_array(a,start,mid,end);
        if(get<2>(left) >= get<2>(right) && get<2>(left) >= get<2>(cross))
            return left;
        else if(get<2>(right) >= get<2>(left) && get<2>(right) >= get<2>(cross))
            return right;
        else
            return cross;
    }
}

void find_max_sub(std::vector<int> &a)
{
    auto res = find_max_sub_exec(a,0,a.size()-1);
    cout<<get<0>(res)<<" "<<get<1>(res)<<" "<<get<2>(res)<<endl;
}
