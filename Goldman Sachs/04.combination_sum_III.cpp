class Solution {
public:
    void solve(vector<int> &temp, vector<vector<int>> &ans, int k, int n, int curr_num)
    {
        // base case
        if(n < 0 || temp.size() > k) return;
        if(n == 0 && temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        // iterating all numbers
        for(int i = curr_num; i <= 9; i++)
        {
            temp.push_back(i);
            solve(temp, ans, k, n-i, i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(temp, ans, k, n, 1);
        return ans;
    }
};