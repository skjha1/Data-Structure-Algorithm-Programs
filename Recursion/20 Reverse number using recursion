#include <iostream.h>
using namespace std;

int reverseNumber(int n) {
 
   static temp,sum;
 
   if(n>0){
  
      temp = n%10;
      sum = sum*10 + temp;

      reverseNumber(n/10);

   } else {
  
     return sum;
   }
 
}

int main() {
 
  int n,reverse;

   cout<<"Enter number";
   cin >> n;

   reverse = reverseNumber(n);
 
   cout << "Reverse of number is" << reverse;
 
   return 0;
}
