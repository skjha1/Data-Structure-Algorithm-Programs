/*Traverse a 4x4 matrix of integers in spiral form.

Input: The first line of input contains an integer T denoting the number of test cases. First four lines of the test case will contain four elements each.
Output: Spiral array will be displayed in a single line.
Constraints:

1 <=T<= 100

1 <=N<= 100
1
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
1
1 5 9 13
2 6 10 14
3 7 11 15
4 8 12 16
1 5 9 13 14 15 16 12 8 4 3 2 6 10 11 7

*/
#include<iostream>
using namespace std;
#define MAX 4
void Spirally_traversing_matrix(int [MAX][MAX]) ;
int main()
 {
 int t,i,j;
 int mat[MAX][MAX] ;
 cin>>t ;
 while(t--)
 {
     for(i=0;i<4;i++)
         for(j=0;j<4;j++)
             cin>>mat[i][j] ;
             
     Spirally_traversing_matrix(mat) ;
     cout<<endl ;
 }
 return 0;
}

void Spirally_traversing_matrix(int mat[MAX][MAX])
{
    int i,a,b,c,d,no ;
   
    no=4 ;
    for(i=0;i<no/2;i++)
    {
        for(a=i;a<no-i*1;a++)
            cout<<mat[i][a]<<" " ;
       
        for(b=i+1;b<no-i*1;b++)
            cout<<mat[b][no-1-i]<<" " ;
           
        for(c=no-2-i;c>=0+i;c--)
            cout<<mat[no-1-i][c]<<" " ;
           
        for(d=no-2-i;d>=0+1+i;d--)
            cout<<mat[d][i]<<" " ;
    }
 
}

