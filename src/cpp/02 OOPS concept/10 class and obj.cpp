#include<bits/stdc++.h>
using namespace std;

class Employee{
    public:
    string Name;
    string Company;
    int Age;
    
    void IntroduceYourself(){
        cout <<"Name  -  "<<Name<<endl;
        cout <<"Company  -  "<<Company<<endl;
        cout <<"Age  -  "<<Age<<endl;
    }
};


int main ()
{
    Employee employee1;
    employee1.Name="Shievndra";
    employee1.Company="No company";
    employee1.Age=23;
    employee1.IntroduceYourself();
    
    Employee employee2;
    employee2.Name= "Nisha";
    employee2.Company="Amazon";
    employee2.Age=18;
    employee2.IntroduceYourself();
    
}
