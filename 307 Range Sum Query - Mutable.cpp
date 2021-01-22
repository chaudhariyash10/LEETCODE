#include <stdc++.h>
using namespace std;

class NumArray
{
    vector<int> segTree;

    void BuildSegmentTree(vector<int> &nums, int index, int start, int end)
    {
        if (start == end)
        {
            segTree[index] = nums[start];
            return;
        }
        else
        {
            int mid = (start + end) / 2;

            BuildSegmentTree(nums, 2 * index + 1, start, mid);
            BuildSegmentTree(nums, 2 * index + 2, mid + 1, end);
            segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
        }
    }

    void updateVal(int index, int val, int start, int end, int curIndex)
    {
        if (index < start || index > end)
            return;

        if (start == end)
        {
            segTree[curIndex] = val;
            return;
        }
        else
        {
            int mid = (start + end) / 2;

            if (index > mid)
            {
                updateVal(index, val, mid + 1, end, 2 * curIndex + 2);
            }
            else
            {
                updateVal(index, val, start, mid, 2 * curIndex + 1);
            }

            segTree[curIndex] = segTree[2 * curIndex + 1] + segTree[2 * curIndex + 2];
        }
    }

    int RangeQuery(int index, int queryLeft, int queryRight, int start, int end)
    {
        if (queryLeft <= start && queryRight >= end)
        {
            return segTree[index];
        }
        else if (queryLeft > end || queryRight < start)
        {
            return 0;
        }

        int mid = (start + end) / 2;

        int leftAns = RangeQuery(2 * index + 1, queryLeft, queryRight, start, mid);
        int rightAns = RangeQuery(2 * index + 2, queryLeft, queryRight, mid + 1, end);

        return leftAns + rightAns;
    }

public:
    NumArray(vector<int> &nums)
    {
        if (nums.size() > 0)
        {
            segTree.resize(4 * nums.size());
            BuildSegmentTree(nums, 0, 0, nums.size() - 1);
        }
    }

    void update(int i, int val)
    {
        updateVal(i, val, 0, (segTree.size() / 4) - 1, 0);
    }

    int sumRange(int i, int j)
    {
        return RangeQuery(0, i, j, 0, (segTree.size() / 4) - 1);
    }
};

int main()
{
    vector<int> nums{1, 3, 5};
    NumArray *obj = new NumArray(nums);
    cout << obj->sumRange(0, 2) << " ";
    obj->update(1, 2);
    cout << obj->sumRange(0, 2);
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */