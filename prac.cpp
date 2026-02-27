#include<iostream>
using namespace std;
void insertion(int arr[],int n)
{
   for(int i=1;i<n;i++)
   {
    int temp=arr[i];
    int j=i-1;
   
   while(j>=0 && arr[j]>temp)
   {
     arr[j+1]=arr[j];
     j--;
   }
   arr[j+1]=temp;
}
}

 int main()
 {
    int arr[]={4,6,7,9,2,1};
    int n=6;

    insertion(arr,n);

    for(int i=0;i<n;i++)
    {

        cout<<arr[i]<<" ";
    }
 }