class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        map<string, int> mp;
        for(int i = 0; i <= n-10; i++)
        {
            string temp = s.substr(i, 10);
            if(mp.find(temp) == mp.end())
                mp.insert({temp, 1});
            else mp[temp]++;
        }
        vector<string> ans;
        for(auto it: mp)
        {
            if(it.second > 1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};