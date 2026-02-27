
#include<iostream>
using namespace std;

class node
{
public :


int data;
node* next;
node* prev;

node(int val)
{
    data=val;
    next=prev=NULL;
}

};

class DoublyList
{
node* head;
node* tail;


 public :
 DoublyList()
 {
    head=tail=NULL;
 }
 void push_front(int val)
 {
    node* newNode=new node(val);
    if(head==NULL)
    {
        head=tail=newNode;
    }
    else
    {
        newNode->next=head;
        head->prev=newNode;
        head=newNode;

    }
 }
     void push_back(int val)
     {
        node* newNode=new node(val);
        if(head==NULL)
        {
            head=tail=newNode;
        }
        else{
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }

     }

     void pop_front()
     {
        if(head==NULL)
        {
            cout<<"Doubly link list is empty"<<endl;
            return;
        }
        node* temp=head;
        head=head->next;
        if(head!=NULL)
        { 
            head->prev=NULL;
            temp->next=NULL;
            delete temp;
        }

     }

     void pop_back()
     {
        if(head==NULL)
        {
            cout<<"The doubly is empty"<<endl;
        }
        node* temp=tail;
        tail=tail->prev;
        if(tail!=NULL)
        {
            temp->prev=NULL;
            tail->next=NULL;
            delete  temp;
        }
       
        
     }
     void insert(int val, int pos)
     {
         if(pos < 0)
         {
             cout << "Invalid position" << endl;
             return;
         }
         if(pos == 0)
         {
             push_front(val);
             return;
         }
     
         node* temp = head;
         for(int i = 0; i < pos - 1; i++)
         {
             if(temp == NULL)
             {
                 cout << "Position out of the DLL" << endl;
                 return;
             }
             temp = temp->next;
         }
     
         node* newNode = new node(val);
     
         if(temp == tail) 
         {
             push_back(val);
          
             return;
         }
     
         newNode->next = temp->next;
         temp->next->prev = newNode;
         temp->next=newNode;
         newNode->prev = temp;   
          
     }
      void print()
 {
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
 }

 void search(int key)
 {
     node* temp=head;
     int pos=0;
     while(temp!=NULL)
     {
      if(temp->data==key)
      {
        cout<<"value : "<<key <<" found pos "<<pos<<endl;
        return;
      }
      temp=temp->next;
      pos++;
     }
     cout<<"Not found "<<endl;
     return;
 }

    };

    int main()
{
DoublyList dll;
dll.push_front(1);
dll.push_front(2);
dll.push_front(3);
dll.push_back(8);
dll.print();
dll.pop_front();
dll.print();
dll.pop_back();
dll.print();
dll.insert(22,0);
dll.print();
dll.search(22);
}