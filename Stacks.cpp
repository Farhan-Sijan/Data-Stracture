#include<iostream>
using namespace std;
#include<list>

class Stack
{ 
      list<int>ll;

      public :
      void push(int val)
      {
        ll.push_front(val);
      }

      void pop()
      {
        ll.pop_front();
      }

      int top()
      {
        return ll.front();
      }

        int empty()
        {
            return ll.size()==0;
        }
};

int main()
{
    Stack s;
    s.push(20);
    s.push(30);
    s.push(40);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
cout<<endl;

}