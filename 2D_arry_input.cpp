#include<iostream>
using namespace std;
int main()
{
    int raw;
    int col;
    int sum[50][50];
    cout<<"Enter your raw number : ";
    cin>>raw;
    cout<<"Enter your colum number : ";
    cin>>col;
    int arr1[raw][col];
    int arr2[raw][col];

    cout<<"for first array : "<<endl;

        for(int i=0;i<raw;i++)
        {
            for(int j=0;j<col;j++)
            { 
                
                cin>>arr1[i][j];
            }
            
        }
        cout<<"for second array : "<<endl;

        for(int i=0;i<raw;i++)
        {
            for(int j=0;j<col;j++)
            { 
                
                cin>>arr2[i][j];
            }
            
        }

           cout<<"First array : "<<endl;

        for(int i=0;i<raw;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout<<arr1[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<"2ndd array : "<<endl;

        for(int i=0;i<raw;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout<<arr2[i][j]<<" ";
            }
            cout<<endl;
        }
        //sum
        for(int i=0;i<raw;i++)
        {
            for(int j=0;j<col;j++)
            {
               sum[i][j]=arr1[i][j]+arr2[i][j];
            }
            cout<<endl;
        }
        for(int i=0;i<raw;i++)
        {
            for(int j=0;j<col;j++)
            {
               cout<<sum[i][j]<<" ";
            }
            cout<<endl;
        }

}