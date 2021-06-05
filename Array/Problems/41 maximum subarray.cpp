// kadane algo says that we will carry a sum until it gives the positive sum
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        for (auto i:nums)
        {
            sum+=i;
            maxi=max(maxi,sum); // everytime take maximum after adding the next element 
            if (sum<0) sum=0; // whenever sum become less then 0 set its value to zero 
        }
        return maxi;
    }
};
// tc sc =O(n), O(1)
