class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0, total = 0, j = 0, odd = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2 != 0)
            {
                odd++;
                if(odd >= k)
                {
                    count = 1;
                    while(nums[j++] % 2 == 0)
                    {
                        count++;
                    }
                    total += count;
                }
            }
            else if(odd >= k)
            {
                total += count;
            }
        }
        return total;
    }
};