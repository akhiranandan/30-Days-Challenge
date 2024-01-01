class Solution {
public:
    int check(long long int d1, long long int d2, long long int u1, long long int u2, long long int x)
    {
        long long int A = x/d1;
        long long int A_ = x - A;
        long long int B = x/d2;
        long long int B_ = x - B;
        long long AIB = x / lcm(d1, d2); 
        long long AuB = A + B - AIB;
        long long A_I_B_ = x - (AuB);
        
        long long int needA = (A_ - A_I_B_ >= u1) ? 0 : u1 - (A_ - A_I_B_);
        long long int needB = (B_ - A_I_B_ >= u2) ? 0 : u2 - (B_ - A_I_B_);

        return (A_I_B_ >= needA + needB);
    }

    int minimizeSet(int d1, int d2, int u1, int u2) {
        long long int low = 1, high = 1e17;
        while(high > low+1)
        {
            long long int mid = (high + low) >> 1;
            if(check(d1, d2, u1, u2, mid)) high = mid;
            else low = mid;
        }
        return high;
    }
};