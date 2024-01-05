class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        long long sum = 0, sum2 = 0;
        for(long long i = 0; i < n; i++)
        {
            sum += arr[i];
            sum2 += (long long)arr[i]*(long long)arr[i];
        }
    long long sn = ((long long)n*(long long)(n+1))/2;
    long long sn2 = ((long long)n*(long long)(n+1)*(2*(long long)n+1))/6;
	long long val1 = (sum - sn);
	long long val2 = (sum2 - sn2);
	val2 = val2/val1;
	long long x = (val1 + val2)/2;
    long long y = x - val1;
    return {(int)x, (int)y};
    }
};
