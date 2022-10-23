static const auto speedup = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution
{
public:
    // return largest power of 2 that evenly goes into n
    int f(int n)
    {
        int x = 1;  // 2^0
        int pow = 0;
        // start from back and find first set bit
        while(!(x & n))
        {
            x <<= 1;
            pow++;
        }
        return pow;
    }
    
    vector<int> grayCode(int n) 
    {
        int size = (1 << n);  // 2^n
        vector<int> nums(size, 0);
        int x = 0;  // number we're changing
        for(int i = 1; i < size; i++)
        {
            int pow = f(i);  // lowest power of 2 that evenly goes into i
            // if bit before (1 << pow) is 0, ADD, if 1, SUBTRACT
            nums[i] = (nums[i - 1] + ((i & (1 << (pow + 1))) ? -(1 << pow) : (1 << pow)));
        }
        return nums;
    }
};
