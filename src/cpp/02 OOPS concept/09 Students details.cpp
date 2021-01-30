#include <iostream>
using namespace std;

class Student
{
private :
	string name;
	int roll;
	float maths;
	float eng;
	float science;
public:
	Student(int r, string n, int m, int e, int s)
	{
		roll = r;
		name = n;
		maths = m;
		eng = e;
		science = s;
	}

	float Totalmarks()
	{
		return maths + eng + science;
	}
	char Grade()
	{
		float avg = Totalmarks() / 3;
		if (avg > 60)
			return 'A';
		else if (avg >= 40 && avg < 60)
			return 'B';
		else
			return 'C';

	}
};

int main()
{
	int roll;
	string name;
	float m, e, s;
	cout << "Enter the roll number of the student " << endl;
	cin >> roll;
	cout << "Enter the name of the students " << endl;
	cin >> name;
	cout << "Enter the marks in the 3 subjects " << endl;
	cin >> m >> e >> s;
	Student s1(roll, name, m, e, s);
	cout << "Total marks of the student is " << s1.Totalmarks() << endl;
	cout << "Grade of the student is " << s1.Grade() << endl;
	return 0;
}