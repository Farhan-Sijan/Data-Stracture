#include<iostream>
using namespace std;

struct Circular_queue
{  
    int* arr; 
    int currsize,cap;
    int f,r;

    Circular_queue(int size)
    {
       cap=size;
        arr=new int[cap];
       currsize=0;
       f=0;
       r=-1;
    }
   void push(int data)
   {
    if(currsize==cap)
    {
      cout<<"The CQ is full";
      return;  
    }
        r=(r+1)%cap;
        arr[r]=data;
        currsize++;

   }

   void pop()
   {
    if(currsize==0)
    {
        cout<<"CQ is empty";
    }
      f=(f+1)%cap;
      currsize--;
   }

   int front()
   {
    if(currsize==0)
    {
        cout<<"CQ is empty";
        return -1;
    }
    return arr[f];
   }
   void print()
   {
    for(int i=0;i<cap;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   }

};

int main()
{
    Circular_queue q(3);
    q.push(1);
    q.push(2);
    q.push(3);
q.pop();
q.push(4);
q.print();

}
