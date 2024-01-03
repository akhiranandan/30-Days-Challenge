class Solution {
public:
vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) 
    {
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++)
        {
            int digits = queries[i][1];
            vector<pair<string, int>> trims;
            for(int j = 0; j < nums.size(); j++)
            {
                string temp = nums[j].substr(nums[j].length()-digits, digits);
                trims.push_back({temp, j});
            }
            sort(trims.begin(), trims.end());
            ans.push_back(trims[queries[i][0]-1].second);
        }
        return ans;
    }
};