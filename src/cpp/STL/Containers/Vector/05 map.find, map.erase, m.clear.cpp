#include<bits/stdc++.h>
using namespace std;

// Lets make a function to print map and getting its size 

void print(map<int,string> &m)
{
	cout<<"Size of the map is "<<m.size()<<endl;
	for (auto pr :m) // this loop is of O(n)
		cout<<pr.first<<" "<<pr.second<<" "<<endl; // O(nlogn)
}
// map uses red black self balencing tree  in backend and it always stored keys in sorted manner 
int main ()
{
	map<int,string>m;
	// map can store any kind of data types even set, vector .. 
	// all the keys of map will always be unique 
	// map stores keys & values in sorted order 
	// if we keep string then it will be stored in lexographical order 

	m[8]="Shivendra"; // insertion takes O(logn)
	m[3]="abc"; // O(logm)
	m[5]="cdc"; // when we wrote this even after there is no value it will take any value by it self 
	m.insert({1,"shiv"});
	// when you want to directly access some specific value in map using m[key] or m.find(key), these are log(n) operations as log(n)time is taken by map to search this key.
	m.erase(3); // O(log(n))
	auto it = m.find(3); // O(long(n))
	m.erase(it); // O(log(n)) // it will delete the key 3 and value 
	m.clear(); // it will clear(delete) full map 
	if (it== m.end())
		cout<<"NO Value ";
	else
		cout <<it->first <<" "<<it->second <<" "<<endl;
	/*print(m);*/
	print(m);
}
// 
