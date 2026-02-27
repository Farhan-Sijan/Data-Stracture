#include<iostream>
using namespace std;

void changeA(int*ptr)
{
    *ptr=20;  //passed by refarence using pointer 
} 

int main()
{
    int a=10;
    changeA(&a);

    cout<<a<<endl;
}