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
   struct queue
      { 
           node* head;
           node* tail;

           queue()
           {
            head=tail=NULL;
           }
       void  push(int data)
       {
           node* newnode=new node(data);
           if(head==NULL)
           {
            head=tail=newnode;
           }
           else
           {
            tail->next=newnode;
            tail=newnode;
           }
       }

       void pop()
       {
           if(head==NULL)
           {
            cout<<"the list is empty"<<endl;
           }
           else{
               node* temp=head;
               head=head->next;
               delete temp;

           }
       }

         int front()
         {
            if(head==NULL)
            {
                cout<<"list is empty";
                return -1;
            }
            else{

                 return head->data;
            }
            
                 
            
         }

      };


         int main()
        {
            queue q;
            q.push(1);
            q.push(2);
            q.push(3);
        
             while(q.head!=NULL)
             {
                cout<<"Front :"<<q.front()<<endl;
                     q.pop();
             }
        
            
        }
  