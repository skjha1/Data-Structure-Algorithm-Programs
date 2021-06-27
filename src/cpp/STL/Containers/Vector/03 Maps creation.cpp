#include<bits/stdc++.h>
using namespace std;
int main ()
{
	map<int,string>m;
	// all the keys of map will always be unique 
	// map stores keys & values in sorted order 
	// if we keep string then it will be stored in lexographical order 

	m[8]="Shivendra"; // insertion takes O(logn)
	m[3]="abc"; // O(logm)
	m[5]="cdc"; // when we wrote this even after there is no value it will take any value by it self 
	m.insert({1,"shiv"});
	/*map<int,string>:: iterator it;
	for (it=m.begin();it!=m.end();++it)
	{
		cout<<it->first<<" "<<it->second<<" "<<endl; // it will give the sorted output 
	}*/
	for (auto &pr :m){
		cout<<pr.first<<" "<<pr.second<<" "<<endl;
		// this will also work as same like above commented code 

	}
}
