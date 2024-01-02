class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> mp;
        // inserting values into map
        for(int i = 0; i < access_times.size(); i++)
        {
            // if string is already present in the map
            if(mp.find(access_times[i][0]) != mp.end())
            {
                // then push the new access time to the vector
                mp[access_times[i][0]].push_back(stoi(access_times[i][1]));
            }

            // if string is NOT present in the map
            else
            {
                // push new value to the map
                mp.insert({access_times[i][0], {stoi(access_times[i][1])}});
            }
        }

        // sorting vectors in map
        for(auto &it: mp)
        {
            sort(it.second.begin(), it.second.end());
        }

        // calculating the answer
        vector<string> ans;
        for(auto it: mp)
        {
            int maxi = it.second.size();
            if(maxi > 2)
            {
                // ans.push_back("inside loop");
                int count = 1, i = 0, j = 1;
                while(i < maxi && j < maxi)
                {
                    if(it.second[j]-it.second[i] < 100)
                    {
                        // ans.push_back("count incr");
                        // ans.push_back(to_string(it.second[j]));
                        count++;
                        j++;
                    }
                    else
                    {
                        if(count > 2)
                        {
                            // ans.push_back("inside loop");
                            ans.push_back(it.first);
                            count = 0;
                            break;
                        }
                        else
                        {
                            count = 1;
                            i++;
                            j = i+1;
                        }
                    }
                }
                if(count > 2) ans.push_back(it.first);
            }
        }
        return ans;
    }
};
