class Solution {
public:

int f(int i, string s, set<string> words, vector<int> &dp)
{
    // base case
    if(i == s.length()) return 1;
    if(dp[i] != -1) return dp[i];
    
    // checking for all substrings
    string temp = "";
    for(int j = i; j < s.length(); j++)
    {
        temp += s[j];
        // if the substring is present in the dictionary
        if(words.find(temp) != words.end())
        {
            // if the substring which is right to temp is also present in the dictionary then return true
            if(f(j+1, s, words, dp)) return dp[i] = 1;
        }
    }
    return dp[i] = 0;
}

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> words;
        for(auto it : wordDict) words.insert(it);
        int n = s.length();
        vector<int> dp(n, -1);
        return f(0, s, words, dp);
    }
};