/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include<unordered_map>

using namespace std;
int main()
{
    string s1;
    string s2;
    
    cin>>s1;
    cin>>s2;
    
    unordered_map<char,int> m;
    
    for(char c:s1){
        m[c]++;
    }
    for(char c:s2){
        m[c]++;
    }
    int x=0;
    for(auto ele:m){
        if(ele.second%2!=0){
            x=1;
        }
    }
    if(x==1){
        cout<< false;
    }
    else
    cout<<true;
    

    return 0;
}
