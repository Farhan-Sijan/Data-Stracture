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
 void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

  int main()
  {
    int n=5;
    int arr[]={4,5,1,2,3};
    insertion(arr,n);
    printArray(arr,n);
  }