#include<iostream>
using namespace std;

class node
{ 
    public:
     
    int val;
    node* next;

    node(int data)
    {
        val=data;
        next=NULL;
    }
};

void insert_Head(node* &head,int val)
{
    
    node* new_node=new node(val);
    new_node->next=head;     
    head=new_node;           
                                
}  
                                 
  void insert_Tail(node* &head,int val)
  {
    node* new_node=new node(val);
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
  } 
    
  void delete_first(node* &head)
  {
    if(head==NULL)
    {
        cout<<"emty"<<endl;
    }
    node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
  }

   void display(node* head)           
       
   {
      node* temp=head;                    
      while (temp!=NULL)
      {
        cout<<temp->val<<" -> ";
        temp = temp->next;
      }
      cout<<"NULL"<<endl;
   }


int main()
{
    node* head =NULL;
    insert_Head(head,2);
    display(head);
    insert_Head(head,1);
    display(head);
    insert_Tail(head,3);
    display(head);
    delete_first(head);
    display(head);


}
