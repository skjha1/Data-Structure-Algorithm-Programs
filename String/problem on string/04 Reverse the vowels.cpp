#include<bits/stdc++.h>
using namespace std;
bool isVowel(char c)
{
    return (c=='a' || c=='A' || c=='e' ||
            c=='E' || c=='i' || c=='I' ||
            c=='o' || c=='O' || c=='u' ||
            c=='U');
}
string reverseVowel(string str)
{
    int j=0;
    string vowel;
    for (int i=0; str[i]!='\0'; i++)
        if (isVowel(str[i]))
            vowel[j++] = str[i];
    for (int i=0; str[i]!='\0'; i++)
        if (isVowel(str[i]))
            str[i] = vowel[--j] ;
 
    return str;
}
int main()
{
    string str;
    cin>>str;
    cout << reverseVowel(str);
    return 0;
}
