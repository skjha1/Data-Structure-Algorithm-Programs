// https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1#
class Solution{
public:	
  int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
    int i=0;
	  int j=M-1;
    while ((i>=0 && i<N) && (j>=0 && j<M)){
      if (mat[i][j]==X)
      {
        return 1;
      }
      else if (mat[i][j]>X)
      {
        j--;
      }
      else 
      {
        i++;
      }
    }
    return 0;
  }
};
