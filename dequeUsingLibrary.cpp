#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque<string> mydeque ;
    char choice;
    do{
     string name;
     char op;
     cout<<"Enter the String You Want to Add in deQue:";
     cin>>name;
     cout<<"Do You Want to Push it to front or Back[F/B]:";
     cin>>op;
     if(op=='B')
     {
        mydeque.push_back(name);
     }
     else if(op == 'F'){
            mydeque.push_front(name);
     }
     else{
        cout<<"Enter Valid Choice!";
     }
     cout<<"Do You Wanna Continue[Y/N]?:";
     cin>>choice;
    }while(choice == 'Y'||choice == 'y');
    cout<<"deQue is:";
    for(auto nam : mydeque)
    {
        cout<<nam<<"  ";
    }
    cout<<"\nThe Size of Queue OR Number of Elements in Queue are:"<<mydeque.size()<<"\n";
    cout<<mydeque.back()<<"  Removed from Back\n";
    mydeque.pop_back();
    cout<<mydeque.front()<<" Removed from front\n";
    mydeque.pop_front();
    mydeque.insert(mydeque.begin() + 1, "MyDeQue");
    cout<<mydeque[1];
    return 0;
}
