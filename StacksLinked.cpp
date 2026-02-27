#include<iostream>
using namespace std;

  struct node
  {
    int data;
    node* next;

      node(int val)
      {
         data=val;
        next=NULL;
      }
  };

  struct list
  {
    node* topnode;
      
     list()
     {
        topnode=NULL;
     }

     void push(int val)
     {
        node* newnode=new node(val);
        newnode->next=topnode;
        topnode=newnode;
     }

     void pop()
     {
        if(topnode==NULL)
        {
            cout<<"stack is empty"<<endl;
            return;
        }
        node* temp=topnode;
        topnode=topnode->next;
        delete temp;
     }

     int top()
     {
        if(topnode==NULL)
        {
            cout<<"Stacks is empty "<<endl;
            return -1;
        }
        return  topnode->data;
     }

     void print()
     {
        node* temp=topnode;
        while (temp!=NULL)
        {
           cout<<temp->data<<" ";
           temp=temp->next;
        }
        cout<<endl;
     }
  };

  int main()
  {
    list ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.print();
    ll.pop();
    ll.print();
  }
  
  