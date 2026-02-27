#include<iostream>
using namespace std;

  struct stack
  {
    int* arr;
    int top; 
    int size;
      
     stack(int size)
     {
        this->size=size;
        arr=new int[size];
        top=-1;

     }

     void push(int element)
     {
        if(size-top>1)
        {
            top++;
            arr[top]=element;
        }
        else{
            cout<<"the stucks overflow"<<endl;
        }

     }

     void pop()
     {
          if(top>=0)
          {
            top--;
          }
          else{
            cout<<"no element"<<endl;
          }
     }

     int tops()
     {
          if(top>=0)
          {
            return arr[top];
          }   
          cout<<"The  stacks is empty"<<endl;
          return -1;
     }

     
  };
  
int main()
{
    stack st(3);
    st.push(32);
    st.push(45);
  st.push(12);
  st.pop();
   cout<<st.tops()<<endl;
     st.pop();
      cout<<st.tops()<<endl;
        
}

