/*
You are given two arrays of integers a and b. For each element of the second array bj you should find the number of elements in array a that are less than or equal to the value bj.

Input Format

The first line contains two integers n, m — the sizes of arrays a and b. The second line contains n integers — the elements of array a.

The third line contains m integers — the elements of array b.

Constraints

1 <= n, m <= 200
- 10^9 <= ai <= 10^9
- 10^9 <= bj <= 10^9

Output Format

Print m integers, separated by spaces: the j-th of which is equal to the number of such elements in array a that are less than or equal to the value bj.

Sample Input 0

5 4
1 3 5 7 9
6 4 2 8
Sample Output 0

3 2 1 4 
*/

#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=200005;
int a[maxn],b[maxn];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++) scanf("%d",a+i);
        for(int i=0;i<m;i++) scanf("%d",b+i);
        sort(a,a+n);
        int ans;
        for(int i=0;i<m;i++)
        {
            if(i==m-1)
            {
                ans=upper_bound(a,a+n,b[i])-a;
                printf("%d\n",ans);
            }
            else
            {
                ans=upper_bound(a,a+n,b[i])-a;
                printf("%d ",ans);
            }
        }
    }
    return 0;
}