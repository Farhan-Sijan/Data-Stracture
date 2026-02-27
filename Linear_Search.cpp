#include<iostream>
using namespace std;

int search(int arr[], int size,int target)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==target)
        {
            return i;
        }
        else {
            return -1;
        }
    }
}
     int main()
     {
         int arr[]={1,2,5,6,7,8,34};
         int size=7;
         int target=10;

         cout<<search(arr, size,target)<<endl;



     }