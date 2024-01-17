class Solution {
public:
// this is similar to word break problem with slight modification
int f(int i, string s, set<string> &words, vector<int> &dp)
{
    // base case
    if(i == s.length()) return 0;
    // overlapping subproblems
    if(dp[i] != -1) return dp[i];
    
    // checking for all substrings
    string temp = "";
    int min_extra = s.length();
    for(int j = i; j < s.length(); j++)
    {
        temp += s[j];
        int curr_extra = 0;
        // if the substring is not present in the dictionary
        if(words.find(temp) == words.end())
        {
            curr_extra = temp.length();
        }
        int next_extra = f(j+1, s, words, dp);
        int total = curr_extra + next_extra;

        min_extra = min(min_extra, total);
    }
    return dp[i] = min_extra;
}
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int> dp(n, -1);
        set<string> words;
        for(auto it: dictionary)
        {
            words.insert(it);
        }
        return f(0, s, words, dp);
    }
};
