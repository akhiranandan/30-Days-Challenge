class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string ans = "";
        int count = 1;
        stack<int> st;
        for(int i = 0; i < S.length(); i++)
        {
            st.push(count);
            count++;
            if(S[i] == 'I')
            {
                while(!st.empty())
                {
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(count);
        while(!st.empty())
        {
            ans += to_string(st.top());
            st.pop();
        }
        return ans;
    }
};