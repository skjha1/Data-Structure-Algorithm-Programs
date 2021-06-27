#include<bits/stdc++.h>
using namespace std;

// Lets make a function to print map and getting its size 

void print(map<int,string> &m)
{
	cout<<"Size of the map is "<<m.size()<<endl;
	for (auto pr :m) // this loop is of O(nlogn)
		cout<<pr.first<<" "<<pr.second<<" "<<endl;
}

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
  print(m);

	}
}
