class solution 
{
  public:
  int *findTwoElement(int *arr, int n) {
    int *res= new int(2);
    int freq[n+1]={0};
    for (int i=0;i<n;i++)
    {
      freq[arr[i]]++; // go to that particular index and increment it by 1 
    }
    for (int i=0;i<n;i++)
    {
      if (freq[arr[i]]>1) // if the index is greater then 1 that means it is a duplicate element 
        res[0]=arr[i];
      if (freq[i]==0) // the index which will be having 0 will be the missing number 
        res[1]=i;
    }
    // this is edge case when result's 1st index will be zero i.e last number is missing 
    /* For example 
    Possibly your code doesn't work correctly for multiple test-cases (TCs).

The first test case where your code failed:

Input:
14
12 7 5 1 13 1 10 8 11 9 2 4 3 6

Its Correct output is:
1 14

And Your Code's output is:
1 0
*/
    if (res[1]==0)
      res[1]=n;
    return res;
  }
};

// O(2n)tc
// o(n)sc
