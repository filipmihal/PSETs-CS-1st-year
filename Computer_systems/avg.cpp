/*
* Multiple line
* comment
*/
#include<iostream>

//Single line comment
using namespace std;

float avg(int arr[], int len){
    float avg = 0;
    for (int i = 0; i < len; i++)
    {
        avg += arr[i];
    }
    
    return avg/len;
}

//This is where the execution of program begins
int main()
{
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    cout << avg(arr, 10);
   return 0;
}