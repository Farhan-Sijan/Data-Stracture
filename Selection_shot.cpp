#include<iostream>
using namespace std;

void selectionshot(int arr[],int n)
{
    
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)

        {
            if(arr[j]<arr[min])
            {
                 min=j;
            }
        }
        swap(arr[min],arr[i]);
    }
}
int main()
{
    int arr[]={5,8,2,4,1,10,7};
    int n=7;

    selectionshot(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}