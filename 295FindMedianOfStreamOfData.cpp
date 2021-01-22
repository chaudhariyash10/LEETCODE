#include <bits/stdc++.h>

using namespace std;

class MedianFinder
{
    vector<int> minHeap, maxHeap;
    int size;

public:
    /** initialize your data structure here. */
    
    MedianFinder()
    {
        size = 0;
    }

    void addNum(int num)
    {
        size++;
        if (maxHeap.size() == 0)
        {
            maxHeap.push_back(num);
            return;
        }

        if(num > maxHeap.front())
            minHeap.push_back(-num), push_heap(minHeap.begin(), minHeap.end());
        else{
            maxHeap.push_back(num), push_heap(maxHeap.begin(), maxHeap.end());
        }

        if(maxHeap.size() > minHeap.size() + 1)
        {
            int temp = maxHeap.front();
            pop_heap(maxHeap.begin(), maxHeap.end());
            maxHeap.pop_back();

            minHeap.push_back(-temp), push_heap(minHeap.begin(), minHeap.end());
        }

        else if(minHeap.size() > maxHeap.size())
        {
            int temp = -minHeap.front();
            pop_heap(minHeap.begin(), minHeap.end());
            minHeap.pop_back();

            maxHeap.push_back(temp), push_heap(maxHeap.begin(), maxHeap.end());
        }
    }

    double findMedian()
    {
        if(size % 2 == 1)
        {
            return maxHeap.front();
        }

        else
        {
            double x = ((double)maxHeap.front() - (double)minHeap.front()) / 2;
            return x;
        }
    }
};
