#include <iostream>
using namespace std;
int main() {
	int t,no,i;
  cin>>t;
  for(i=0;i<t;i++)
    cin>>no;
  char s[no];
  char rs[no];
  cin>>s;
  for (i=0;s[i]!='\0';i++)
  {
    
  }
  i=i-1;
  for (int j=0;i>=0;i-=1,j++)
  {
    rs[j]=s[i];
  }
  rs[i]='\0';
  cout<<rs;
  
	return 0;
}