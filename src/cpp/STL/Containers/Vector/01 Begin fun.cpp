/*- Vector is same like dynamic array  
  - when we are going to del or insert any val it is going to resize by itself 
  - that is their storage being handalled automatically by containers 
*/
// here we are going to use vector element .begin()
// .begin() will return 1st element of array 
// there shoud not be any parameter passed to begin ()
/*
* begin syntax 
* vectorname.begin()
Parameters :
No parameters are passed.
*/

//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	vector<int> my_vect{ 1,5,9,8,7 };
//	for (auto i = my_vect.begin(); i != my_vect.end(); ++i)
//		cout << ' ' << *i;
//
//	return 0;
//}


//-------------------------------------------------------------------------------------------------------------------------------------

//another example for string 

#include <iostream>
#include <string>
#include<vector>
using namespace std;
int main()
{
	// declaration of vector in container 
	vector <string> my_vect  { "My","Name","Is SHIVENDRA" };
	// here we are using begin and end to print the full string 
	for (auto i = my_vect.begin(); i != my_vect.end(); ++i)
		cout << ' ' << *i;
	return 0;
}