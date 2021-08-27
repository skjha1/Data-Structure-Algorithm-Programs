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
    Employee(string name, string company, int age){
        Name=name;
        Company=company;
        Age=age;
    }
};


int main ()
{
    Employee employee1=Employee("Shivendra","No-company",23);
    employee1.IntroduceYourself();
    
    Employee employee2=Employee("Nisha","Amazon",18);
    employee2.IntroduceYourself();
    
}
