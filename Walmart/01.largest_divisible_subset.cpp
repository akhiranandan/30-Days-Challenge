class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        map<int, vector<int>> mp;
        int maxi = 1;
        for(int i = 0; i < n; i++)
        {
            mp.insert({nums[i], {nums[i]}});
            for(auto it: mp)
            {
                if(it.first != nums[i] && (it.first % nums[i] == 0 || nums[i] % it.first == 0))
                {
                    if(it.second.size()+1 > mp[nums[i]].size())
                    {
                        vector<int> arr = it.second;
                        arr.push_back(nums[i]);
                        mp[nums[i]] = arr;
                        if(mp[nums[i]].size() > maxi) maxi = mp[nums[i]].size();
                    }
                }
            }
            if((int)mp[nums[i]].size() > maxi) maxi = (int)mp[nums[i]].size();
        }
        vector<int> ans;
        for(auto it: mp)
        {
            if(it.second.size() == maxi) ans = it.second;
        }
        return ans;
    }
};