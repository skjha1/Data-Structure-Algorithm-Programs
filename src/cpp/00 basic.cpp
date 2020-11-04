As you can see in the image, this was the program that we had executed in our previous lecture. Now we will discuss what each line of code in the program does.

1. Let's start with the 1st line of code "#include<iostream>" - this whole text is called a header file.

In this line of code include is a keyword used to add libraries in our program. "iostream" is the name of a library, added to our program. The iostream library helps us to get input data and show output data. The iostream library also has many more uses; it is not only limited to input and output but for now, we will not go into more detail on this.   

2. One more thing to consider here is that the 2nd line of code is blank; there is no code written. The thing to consider here is that it doesn't matter how many lines you have left empty in a C++ program, the compiler will ignore those lines and only check the ones with the code.

3. Now onto the 3rd line of code "int main() {" - In this line of code, "int" is a return type which is called integer and "main()" is a function, the brackets "()" denotes that it is a function. The curly brace "{" indicates that it is an opening of a function, and the curly brace "}" indicates that it is the closing of a function. Here I will give you an example to better understand the functionality of "int main()." Imagine that you own a coffee shop, and you have some employees who work for you. Let's name (Anna, Blake, Charlie) as the three employees. The function of Anna is to take orders, the function of Blake is to make coffee, and Charlie's function is to deliver coffee. Now when Anna gets a coffee order, she will call Blake to make the coffee, and when the coffee is ready, Blake will call Charlie to deliver the coffee. In this scenario, we can say that Anna is the primary function from which all the other tasks will start, and coffee is our return value (Something charlie finally gives to Blake). In this line of code, "main" is a reserved keyword, and we cannot change it to some other keyword. This was just an analogy, and you will understand this very well in upcoming tutorials.

4. Now let's talk about the 4th line of code 'std::cout<<" hello world";' - In this line of code "std" is a namespace, "::" is the scope resolution operator and "cout<<" is a function which is used to output data, "hello world" is our output string and ";" is used to end a statement. The code "std::cout" tells the compiler that the "cout" identifier resides in the std namespace. Main key points here are:

We can write as many statements as you want in a single line, but I recommend you to write one statement per line to keep the code neat and clean.
Anything which is written between double quotation " " is a string literal (More on strings later).
5. Now let's talk about the 5th line of code "return 0" - In this line of code, return keyword will return 0 as an integer to our main function "int main()" as we have discussed before. Returning 0 as a value to the main function means successful termination of the program.

So that was the anatomy of a C++ program. I hope you understood the functions of various parts in a C++ program.