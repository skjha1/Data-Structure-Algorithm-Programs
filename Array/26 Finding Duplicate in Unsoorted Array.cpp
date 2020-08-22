#include<iostream>
using namespace std;
int main()
{
	
	int a[16] = {8,3,6,4,6,5,6,8,2,7,8,55,55,55,99,99};
	for(int i=0;i<15;i++)
	{
		int count = 1;
		if(a[i]!=-1)
		{
			for(int j=i+1;j<16;j++)
			{
				if(a[j]==a[i])
				{
					count++;
					a[j]=-1;
				}
			}
			if(count>1)
				cout<<"Duplicate element is: "<<a[i]<<" repeated for "<<count<<" times"<<endl;
		}
	}
	cout<<endl;
	return 0;
}
