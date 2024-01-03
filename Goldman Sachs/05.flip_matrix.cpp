class Solution {
private:
    set<pair<int, int>> st;
    int rows;
    int cols;
public:
    Solution(int m, int n) {
        rows = m;
        cols = n;
    }
    
    vector<int> flip() {
        int i = rand()%rows;
        int j = rand()%cols;
        // if values are not present in set
        if(st.find({i,j}) == st.end())
        {
            st.insert({i, j});
            return {i,j};
        }
        return flip();
    }
    
    void reset() {
        st.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */