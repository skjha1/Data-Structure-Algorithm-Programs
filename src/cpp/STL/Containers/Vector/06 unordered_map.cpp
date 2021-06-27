#include<bits/stdc++.h>
using namespace std;

// Lets make a function to print map and getting its size 

void print(unordered_map<int,string> &m)
{
	cout<<"Size of the map is "<<m.size()<<endl;
	for (auto pr :m)
		cout<<pr.first<<" "<<pr.second<<" "<<endl;
}

int main ()
{
	// 1. inbuilt impletation : It uses hash table it dont uses trees like map // here keys will make hash value 
	// 2. Time complexity  : O(1)-> Insertion and access 
	// 3. valid keys datatypes  : we cant keep all type of data types like pair of pair 
	// we can use int double string float ... cz these all have possible  hash value 
	unordered_map<int,string>m;
	// unordered map does not store in sorted manner  it will print randomly 

	m[8]="Shivendra"; // insertion takes O(1)
	m[3]="abc";
	m[5]="cdc";
	m.insert({1,"shiv"});
	/*map<int,string>:: iterator it;
	for (it=m.begin();it!=m.end();++it)
	{
		cout<<it->first<<" "<<it->second<<" "<<endl; // it will give the sorted output 
	}*/
	/*m.find // O(1)
	m.earese// o(1)*/
	for (auto &pr :m){
		cout<<pr.first<<" "<<pr.second<<" "<<endl;
		// this will also work as same like above commented code 

	}
}
