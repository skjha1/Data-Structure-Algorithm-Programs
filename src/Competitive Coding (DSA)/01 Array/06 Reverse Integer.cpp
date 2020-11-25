class Solution {
public:

	int reverse(int x) {
        long long res = 0;
        while(x != 0)
        {
            res = res*10 + x%10;
            x /= 10;
            
            if(abs(res) > INT_MAX)
                return 0;
        }
        return res;
    }
};
//Input: x = 123
//Output: 321