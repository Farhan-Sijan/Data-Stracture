#include<iostream>
using namespace std;
  
void bubbleshot(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
} 

int main()
{
    int arr[]={4,5,9,8,10,23,1};
     int n=7;

     bubbleshot(arr,n);

     cout<<"shorted array is : ";
     for(int i=0;i<n;i++)
         {
            cout<<arr[i]<<" ";
         }
}