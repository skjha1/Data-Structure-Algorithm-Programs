
#include<bits/stdc++.h>
using namespace std;

/*given N string, print unique sting 
in Lexicpgraphical order with their frequency 

*/

// map uses red black self balencing tree  in backend and it always stored keys in sorted manner 
int main ()
{
	map<string , int >m; // key as string and value as integer 
	int n;
	cin>>n;
	for (int i=0;i<n;++i)
	{
		string s;
		cin>>s;
		/*m[s]=m[s]+1; or we can write m[s]++ both are same */
		m[s]++;
	}
	for (auto pr : m)
	{
		cout <<pr.first<<" "<< pr.second <<" " <<endl;
	}
	
}
// 
