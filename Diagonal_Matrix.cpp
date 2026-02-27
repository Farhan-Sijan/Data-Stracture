#include<iostream>
using namespace std;
  
int diagonalSum(int mat[4][4],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                sum+=mat[i][j];
            }
            else if(j==n-1-i)
            {
                sum+=mat[i][j];
            }
        }
    }
    return sum;
}
    int main()
    {
       int matrix[4][4]={{1,2,3,4},{4,5,6,7},{2,3,4,5},{7,6,5,4}};
       int n=4;
       cout<<diagonalSum(matrix,n)<<endl; 
    }