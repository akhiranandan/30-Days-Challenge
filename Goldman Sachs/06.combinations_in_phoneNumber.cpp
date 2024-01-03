class Solution {
public:
    void solve(string digits, string &temp, vector<string> &ans, int ind, map<int, string> &mp)
    {
        // base case
        if(temp.size() == digits.length())
        {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; (digits[ind] == '7' || digits[ind] == '9') ? i < 4 : i < 3; i++)
        {
            string s = mp[digits[ind]];
            temp.push_back(s[i]);
            solve(digits, temp, ans, ind+1, mp);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        map<int, string> mp;
        mp.insert({'2', "abc"});
        mp.insert({'3', "def"});
        mp.insert({'4', "ghi"});
        mp.insert({'5', "jkl"});
        mp.insert({'6', "mno"});
        mp.insert({'7', "pqrs"});
        mp.insert({'8', "tuv"});
        mp.insert({'9', "wxyz"});
        string temp;
        vector<string> ans;
        solve(digits, temp, ans, 0, mp);
        return ans;
    }
};