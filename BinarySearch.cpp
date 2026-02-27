#include<iostream>
using namespace std;

int binarySearch(int arr[],int n ,int tar)
{
    int st=0;
    int end=n-1;

    while(st<=end)
    {
        int mid=st+(end-st)/2;
         
        if(tar>arr[mid])
        {
            st=mid+1;
        }
        else if(tar<arr[mid])
        {
            end=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main()

{
       int arr[]={1,2,3,4,5,6,7};
       int tar=4;
       int n=7;
       cout<<binarySearch(arr,n,tar)<<endl;
}