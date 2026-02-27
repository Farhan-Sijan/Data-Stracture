#include<iostream>
using namespace std;

struct student{

    int id;
    string name;
    string department;
    float cgppa;
};

int main()
{  
    int n;
    cout<<"Enter number of student : ";
    cin>>n;
    student students[100];
       
    cout<<"For studnet id : "<<endl;
      for(int i=0;i<n;i++)
      {
          cout<<"Enter data for student (id): " <<i+1<<endl;
          cin>> students[i].id;
      }
     cin.ignore(); //for clear input
      cout<<"For studnet name : "<<endl;
      for(int i=0;i<n;i++)
      {
          cout<<"Enter data for student (name): " <<i+1<<endl;
          cin>> students[i].name;
      }
      cin.ignore();
      cout<<"For studnet dept : "<<endl;
      for(int i=0;i<n;i++)
      {
          cout<<"Enter data for student (dept): " <<i+1<<endl;
          cin>> students[i].department;
      }
      cin.ignore();
      cout<<"For studnet cg : "<<endl;
       for(int i=0;i<n;i++)
       {
        cout<<"Enter data for student (cgpa): " <<i+1<<endl;
        cin>>students[i].cgppa;
       }

       float high=students[0].cgppa;
    
       for(int i=0;i<n;i++)
       {
        if(students[i].cgppa>high)
        {
            high=students[i].cgppa;
          
        }

              for(int i=0;i<n;i++)

              {
                if(students[i].cgppa==high)
                {
                    cout<<"\nID is : "<<students[i].id<<endl 
                    <<" \nname is : "<<students[i].name<<endl
                    <<"\ndept name : "<<students[i].department<<endl
                    <<"\ncgpa is : "<<students[i].cgppa<<endl;
                }
              }
}
  cin.ignore();
string searchdept;
cout<<"Enter your dept for search : "<<endl;
cin>>searchdept;

bool found= false;
   
for(int i=0;i<n;i++)
{
    if(students[i].department==searchdept)
    {
        cout << "ID : " << students[i].id << " Name : " << students[i].name
                 << " CGPA : " << students[i].cgppa << endl;
                 found=true;

    }
}
if(found==false)
{
    cout<<"NO dept found "<<endl;
}

}