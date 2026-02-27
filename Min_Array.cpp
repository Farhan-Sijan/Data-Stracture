#include<iostream>
using namespace std;
int main()
{
   int size;
   cout<<"Enter your array size";
   cin>>size;

   int nam[size];

   for(int i=0 ;i<size;i++)
   {
    cin>>nam[i];
   }

     int smallest = nam[0];
     int high = nam[0];

     for(int i=0;i<size;i++)
     {
        if(nam[i]<smallest)
        {
            smallest=nam[i];
        }
     }

     for(int i=0;i<size;i++)
     {
        if(nam[i]>high)
        {
            high=nam[i];
        }
     }
     cout<<"Hightest number is : "<<high<<endl;

  cout<<"Small number is : "<<smallest<<endl;

}