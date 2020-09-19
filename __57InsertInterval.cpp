#include <stdc++.h>

using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> ans;
    int flag = 1;
    for (int i = 0; i < intervals.size(); i++){
        if(intervals[i][0] > newInterval[0] && flag){
            ans.push_back(newInterval);
            ans.push_back(intervals[i]);
            flag = 0;
        }

        else{
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> intervals{{1,3},{2,5},{6,9}};
    vector<int> newInterval = {9, 10};
    
    intervals = insert(intervals, newInterval);

    for (int i = 0; i < intervals.size(); i++){
        cout << intervals[i][0] << " " << intervals[i][1];
        cout << endl;
    }
} 