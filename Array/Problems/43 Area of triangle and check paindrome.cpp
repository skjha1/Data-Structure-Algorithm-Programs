#include<iostream>
#include<cmath>
using namespace std;

int main() 
{
   // Try out your code here
    int a,b,c,d,s,area;
	cin>>a>>b>>c;
	s=(a+b+c)/2;
	d=s*(s-a)*(s-b)*(s-c);
	area=sqrt(d);
	cout<<"Area of a triangle = "<<area<<endl;
	int temp,r,sum=0;
	temp=area;
	while(area>0){
		r=area%10;
		sum=sum*10+r;
		area=area/10;
	}
	if (temp==sum)
	{
		cout<<"Area is palindrome";
	}
	else
	{
		cout<<"Area is not palindrome";
	}


    return 0;
}
