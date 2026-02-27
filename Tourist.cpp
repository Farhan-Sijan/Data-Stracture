#include <iostream>
using namespace std;
 
 int globalToken=1;

  int trcount =0, medcount=0,bscount=0,gocount=0;

  int trserve=0,medserve=0,bsserve=0,goserve=0;
    
  void issueToken()
  {
    int type;
    cout<<"Choose visa type : "<<endl;
    cout << "1. Tourist (TR) : "<<endl;
    cout << "2. Medical (MED) :  "<<endl;
    cout << "3. Business (BS) : "<<endl;
    cout << "4. Government (GO) : "<<endl;
    cout << "Your choice : "<<endl;
    cin >> type;

      if(cin.fail())
      {
        cin.clear();
        cout<<"INVALID INPUT....PLEASE TRY AGAIN "<<endl;
        return;
      }

      if(type==1&&trcount<25)
      {
        cout<<"Your token is : "<<globalToken<<endl;
        trcount++;
        globalToken++;
      }
      else if (type == 2 &&medcount < 25)
      {
        cout << "Your token is: MED-" << globalToken << endl;
        medcount++;
        globalToken++;
      }

      else if (type == 3&&bscount < 25)
          {
            cout << "Your token is: BS-" << globalToken << endl;
            bscount++;
            globalToken++;
          }
          else if (type == 4&&gocount < 25) 
          {
            cout << "Your token is: GO-" << globalToken << endl;
        gocount++;
        globalToken++;
          }
          else {
            cout << "Limit reached or invalid input." << endl;
          }
  }

  void callnext()
  {
    int counter;
    cout<<"Enter counter number (1-4): "; 
    cin >>counter;
      
       if(cin.fail())
       {
        cin.clear();
        cout<<"INVALID INPUT,TRY AGAIN :  ";
          return;
       }

       if (counter == 1) {
        if (trserve < trcount) {
            trserve++;
            cout << "Counter 1, Please serve TR-" << trserve << endl;
        }
        else {
            cout << "Counter 1 is idle." << endl;
        }
  }
  else if (counter == 2) {
    if (medserve < medcount) {
        medserve++;
        cout << "Counter 2, Please serve MED-" << medserve << endl;
    }
    else {
        cout << "Counter 2 is idle." << endl;
    }
}
else if (counter == 3) {
    if (bsserve < bscount) {
        bsserve++;
        cout << "Counter 3, Please serve BS-" << bsserve << endl;
    }
    else {
        cout << "Counter 3 is idle." << endl;
    }
}
    else if (counter == 4) {
        if (goserve < gocount) {
            goserve++;
            cout << "Counter 4, Please serve GO-" << goserve << endl;
        }
        else {
            cout << "Counter 4 is idle." << endl;
        }
  }
 
  
else {
    cout << "Invalid counter number!" << endl;
}
}


void summary()
{
    cout<<"Daily summary report is : "<<endl;
    cout << "Counter 1 Tourist : " << trserve<<endl;
    cout << "Counter 2 Medical : " << medserve<<endl;
    cout << "Counter 3 Business :  " << bsserve << endl;
    cout << "Counter 4 Government :  " << goserve<<endl;
}

   int main()
   {
    int choice;

      while(true)
      {
        cout<<"Visa system  : "<<endl;
       cout<<" (1)  Request token no : "<<endl;
       cout<< " (2) call the next customer : "<<endl;
       cout<<"(3) request summary report : "<<endl;
       cout<<"(4) EXIT "<<endl;
       cin>>choice;
      
      if (cin.fail()) {
        cin.clear();
        cout << "INVALID NUMBER. PLEASE TRY AGAIN." << endl;
        continue;
    }

        if(choice==1)
        {
            issueToken();
        }
        else if (choice==2)
        {
            callnext();
        }
        else if (choice==3)
        {

            summary();
        }
        else if(choice==4)
        {
            cout<<"EXIT THIS PROGRAM "<<endl;
            break;
        }
        else
        {
            cout<<"invalid type"<<endl;
        }

   }
}
