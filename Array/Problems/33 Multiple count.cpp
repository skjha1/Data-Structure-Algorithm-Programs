/*
Input:
7 3
1
51
966369
7
9
999996
11

Output:
4
*/

#include <iostream> 
using namespace std;


int main()
{
    int n, k;
    cin >> n >> k;
    
    int A[n];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (A[i] % k == 0)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;


}
