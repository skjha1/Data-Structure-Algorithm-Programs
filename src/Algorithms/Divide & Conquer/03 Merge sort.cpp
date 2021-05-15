class Solution {
public:
   void merge(vector<int>& nums, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int A[n1], B[n2];
    
    for(int i = 0; i < n1; i++)
        A[i] = nums[l + i];
    
    for(int i = 0; i < n2; i++)
        B[i] = nums[m + 1 + i];
    
    int i = 0, j = 0;
    int k = l;
    
    while(i < n1 && j < n2)
    {
        if(A[i] <= B[j])
            nums[k++] = A[i++];
        else
            nums[k++] = B[j++];
    }
    
    while(i < n1)
        nums[k++] = A[i++];
    while(j < n2)
        nums[k++] = B[j++];
}

void mergeSort(vector<int>& nums, int l, int r)
{
    if(l >= r)  //remember to put the equal to sign
        return;
    
    int m = l + (r - l)/2;
    mergeSort(nums, l, m);
    mergeSort(nums, m + 1, r);
    merge(nums, l, m, r);
}

vector<int> sortArray(vector<int>& nums) 
{
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
}  
        
    
};
