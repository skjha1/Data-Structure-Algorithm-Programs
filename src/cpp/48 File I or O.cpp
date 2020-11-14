/*   The file is a patent of data which is stored in the disk. Anything written inside the file is called a patent, for example: “#include” is a patent.
The text file is the combination of multiple types of characters, for example, semicolon “;” is a character.

The computer read these characters in the file with the help of the ASCII code. Every character is mapped on some decimal number. For example, 
ASCII code for the character “A” is “65” which is a decimal number. These decimal numbers are converted into a binary number to make them readable for 
the computer because the computer can only understand the language of “0” and “1”.
The reason that computers can only understand binary numbers is that a computer is made up of switches and switches only perform two operations “true” or “false”.

File Input and Output in C++
The file can be of any type whether it is a file of a C++ program, file of a game, or any other type of file. There are two main operations which can be performed on files

Read File
Write File
An image is shown below to show the process of file read and write.(https://codewithharry.com/videos/cpp-tutorials-in-hindi-59)

As shown in figure 1,

The user can provide input to the C++ program by using keyboard through “cin>>” keyword
The user can get output from the C++ program on the monitor through “cout<<” keyword
The user can write on the file
The user can read the file


File I/O in C++: Reading and Writing Files
These are some useful classes for working with files in C++

fstreambase
ifstream --> derived from fstreambase
ofstream --> derived from fstreambase
In order to work with files in C++, you will have to open it. Primarily, there are 2 ways to open a file:

Using the constructor
Using the member function open() of the class
An example program is shown below to demonstrate the concept of reading and writing files
*/
#include<iostream>
#include<fstream>

using namespace std;

int main(){
    string st = "Harry bhai";
    // Opening files using constructor and writing it
    ofstream out("sample60.txt"); // Write operation
    out<<st;

    return 0;
}

/*
We have created a string “st” which has a value “harry Bhai”
Object “out” is created of the type ofstream and the file “sample60.txt” is passed to it
The string “st” is passed to object “out”
*/

#include<iostream>
#include<fstream>

using namespace std;

int main(){
    string st2;
    // Opening files using constructor and reading it
    ifstream in("sample60b.txt"); // Read operation
    in>>st2;
    getline(in, st2);  
    cout<<st2;

    return 0;
}
/*
1 We have created a string “st2” which is empty
2 We have made a text file “sample60b.txt” and written “This is coming from a file” in it
3 Object “in” is created of the type instream and the file “sample60b.txt” is passed to it
4 The function “getline” is called and the object “in” and the string “st2” are passed to it. The main thing to note here is that the function “getline” 
is used when we want to read the whole line
5 String “st2” is printed
*/

