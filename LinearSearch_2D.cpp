#include<iostream>
using namespace std;
int main()
{
    int raw;
    int col;
    int key;

    cin>>raw;
    cin>>col;

       int arr[raw][col];

       for(int i=0;i<raw;i++)
       {
           for(int j=0;j<col;j++)
           { 
               
               cin>>arr[i][j];
           }
           
       }

       for(int i=0;i<raw;i++)
       {
           for(int j=0;j<col;j++)
           { 
               
             cout<<arr[i][j]<<" ";;
           }
           cout<<endl;
           
       }
        
       bool found=false;  

       cout<<"Enter an Index number you want : ";
       cin>>key;

       for(int i=0;i<raw;i++)
       {
           for(int j=0;j<col;j++)
           { 
               
              if(arr[i][j]==key)
                {
                    cout<<"YOur element is : "<<key<<endl;
                    found=true;
                }
           }
           
       }
       if(found==false){
        cout<<"not found ";
       }
       
       }
