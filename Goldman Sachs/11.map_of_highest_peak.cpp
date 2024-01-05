class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans = isWater;
        queue<pair<int, int>> q;

        // initialising matrix with infinite & zeroes
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isWater[i][j] == 1)
                {
                    ans[i][j] = 0;
                    q.push({i,j});
                }
                else
                {
                    ans[i][j] = INT_MAX;
                }
            }
        }

        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            vector<int> first = {0,0,-1,1};
            vector<int> second = {-1,1,0,0};

            // moving in all 4 directions
            for(int k = 0; k < 4; k++)
            {
                int x = i + first[k];
                int y = j + second[k];

                // if difference is more than one, change it and add to queue
                if(x >= 0 && x < m && y >= 0 && y < n && ans[x][y] > 1+ans[i][j])
                {
                    ans[x][y] = 1+ans[i][j];
                    q.push({x,y});
                }
            }
        }
        return ans;
    }
};