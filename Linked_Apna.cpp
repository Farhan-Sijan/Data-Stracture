#include<iostream>
using namespace std;

 class node
 {  
     public : 
      
     int data;
     node* next;

     node(int val)
     {
        data=val;
        next=NULL;
     }
 };

 class List
 {
    node* head;
    node* tail;

    public :

    List()
    {
        head=tail=NULL;
    }
      void push_front(int val)
      {
        node* new_node=new node(val);

          if(head==NULL)
          {
            head=tail=new_node;
            return;
          }
          else
          {
            new_node->next=head;
            head=new_node;
          }
          cout<<endl;
      }

      void push_back(int val)
      {
        node* newNode=new node(val);
        if(head==NULL)
        {
            head=tail=newNode;
        }
        else{
              tail->next=newNode;
              tail=newNode;
        }
      }
           void pop_front()
           {
              if(head==NULL)
              {
                cout<<"LL is emty"<<endl;
                return;
              }
              node* temp=head;
              head=head->next;
              temp->next=NULL;
              delete temp;
           }
             
         void pop_back()
         {
            
            if(head==NULL)
            {
                cout<<"The LL is empty"<<endl;
                return;
            }
            node* temp=head;
            while(temp->next!=tail)
            {
                temp=temp->next;
            }
              temp->next=NULL;
              delete tail;
              tail=temp;
               
         }

         void insert(int val,int pos)
         {
            if(pos<0)
            {
                cout<<"Invalid position"<<endl;
                return;
            }
            if(pos==0)
            {
                push_front(val);
                return;
            }
            
            node* temp=head;
            for(int i=0;i<pos-1;i++)
            {
                if(temp==NULL)
                {
                    cout<<"Position out of the LL"<<endl;
                }
                temp=temp->next;
            }
            node* newNode=new node(val);
            newNode->next=temp->next;
            temp->next=newNode;
         }

         void deletion(int val)
         {
          if(head==NULL)
          {
            cout<<"List is empty"<<endl;
            return;
          }

          if(head->data==val)
          {
            pop_front();
            return;

          }

          if(tail->data==val)
          {
            pop_back();
            return;
          }
          node* temp=head;
          while(temp->next->data!=val)
          {
            temp=temp->next;
          }
          node* todelete=temp->next;
          temp->next=temp->next->next;
          delete todelete;
         }
 
      void printLL() 
      {
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
      }
       int search(int key)
       {
         node* temp=head;
         int i=0;
            while(temp!=NULL)
          {
            if(temp->data==key)
            {
                return i;
            }
            temp=temp->next;
            i++;
          }
return -1;          
       }


 };

int main()
{
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
   // ll.push_back(4);
    //ll.pop_front();
    //ll.pop_back();
    ll.insert(4,3);
    ll.printLL();
    ll.deletion(2);
    ll.printLL();
     ll.deletion(4);
     ll.printLL();

   cout<< ll.search(4)<<endl;

}