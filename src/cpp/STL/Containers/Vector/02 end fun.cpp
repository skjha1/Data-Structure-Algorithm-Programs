  /*- Vector is same like dynamic array  
  - when we are going to del or insert any val it is going to resize by itself 
  - that is their storage being handalled automatically by containers 
*/
/*
* end () is also used in above program so its syntax is similar to begin ()
* end () return an iterators pointing to next to last elements
* vectorname.end()
Parameters :
No parameters are passed.
Returns :
This function returns a bidirectional
iterator pointing to next to last element.


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

