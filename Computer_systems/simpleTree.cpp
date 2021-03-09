/*
* Multiple line
* comment
*/
#include<iostream>

//Single line comment
using namespace std;

//This is where the execution of program begins
int main()
{
   int size = 5;
   char temp[size*2-1];


    for (int i = 0; i < size*2-1; i++)
   {
       temp[i] = ' ';
   }
   for (int i = 0; i < size*2-1; i++)
   {
       cout << temp[i];
   }
   cout << '\n';

   for (int i = 0; i < size; i++)
   {
        temp[size/2+i] = '*'; 
        temp[size/2-i] = '*'; 
        for (int a = 0; a < size*2-1; a++){
            cout << temp[a];
        }
        cout << '\n';
   }
   
   return 0;
}