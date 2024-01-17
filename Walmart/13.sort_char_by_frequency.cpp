class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for(int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
        }
        vector<pair<int, char>> temp;
        for(auto it: mp)
        {
            temp.push_back({it.second, it.first});
        }
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());
        string ans = "";
        for(int i = 0; i < temp.size(); i++)
        {
            int j = temp[i].first;
            while(j--)
            {
                ans += temp[i].second;
            }
        }
        return ans;
    }
};