#include<iostream>
using namespace std;

struct queue
{
    int arr[100];
    int front;
    int rear;

     queue()
     {
        front=0;
        rear=0;
     }

     void push(int data)
    {
        if(rear==100)
        {
            cout<<"the queue is overflow"<<endl;
            return;
        }
        arr[rear++]=data;
    }

    void pop()
    {
        if(front==rear)
        {
            cout<<"the queue is empty"<<endl;
            return;
        }

        front++;
    }

    int frontt()
    {
        if(front==rear)
        {
            cout<<"the queue is empty"<<endl;
            return -1;
        }
        return arr[front];

    }

    void display()
    {
        if(front==rear)
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        cout<<"Queue elements : ";
        for(int i=front;i<rear;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    queue q;
    q.push(2);
    q.push(3);
    q.push(5);
       q.display();
    q.pop();
    q.display();
}
