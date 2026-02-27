#include<iostream>
using namespace std;

void print(int *p)
{
    cout<<p<<endl;
    cout<<*p<<endl;
}

void update(int *p)
{
    *p=*p+1;
    p=p+1;
    cout<<"After "<<p<<endl;
    cout<<*p<<endl;
    
}

int main()
{
    int value=6;
    int *p=&value;
    print(p);
    update(p);
    cout<<"BEfore : "<<p<<endl;
}