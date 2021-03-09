#include<iostream>
using namespace std;

constexpr int no_value = -999;
int temperatures[] { 10, 12, no_value, no_value, 20, 14, 6, -1, -5, 0, no_value, 1, -3 };

int getMargin(int arr[], int len){
    int min = 0;
    for (int i = 0; i < len; i++)
    {
        if(min > arr[i] && arr[i] != no_value){
            min = arr[i];
        }
    }
    return abs(min);
}

void temp(int arr[], int len){
    int margin = getMargin(arr, len);
    int latestValue = 0;
    int currentTemp = 0;

    for (int i = 0; i < len; i++)
    {
        currentTemp = (arr[i] == no_value) ? latestValue : arr[i];
        if(currentTemp < 0)
        {
            for (int q = margin; q >= 0; q--)
            {
                cout << (currentTemp+q <= 0 ? '*' : ' ');
            }
        }
        else {
            for (int b = 0; b < margin; ++b)
            {
                cout << ' ';
            }
            
            for (int a = 0; a <= currentTemp; a++)
            {
                cout << '*';
            }

        }
        latestValue = currentTemp;
        cout << '\n';  
    }
}

int main()
{
    int arrSize = *(&temperatures + 1) - temperatures;
    temp(temperatures, arrSize);
   return 0;
}