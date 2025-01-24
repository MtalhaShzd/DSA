#include <iostream>
using namespace std;
void insert_First(int arr[],int num,int sizeofarray);
void insert_last(int arr[],int num,int sizeofarray);
void insert_Any(int arr[],int num,int sizeofarray);
int is_Full(int arr[],int sizeofarray);
void del_First(int arr[],int sizeofarray);
void del_last(int arr[],int sizeofarray);
void del_Any(int arr[],int index,int sizeofarray);
int main()
{
    int arr[5];
    int sizeofarray = sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter an Array of 5 numbers and left atleast one space blank[For Leaving Empty put 0]:\n";
    for(int i = 0;i<sizeofarray;i++)
    {
       cin>>arr[i];
    }
    cout<<"D:Deletion"<<endl;
    cout<<"I:Insertion"<<endl;
    char choice;
    cout<<"Which Operation do You want to Perform on it?";
    cin>>choice;
    switch(choice)
    {
        case 'I':
        {
            char choice;
            int num;
            cout<<"Enter the Number you want to insert:";
            cin>>num;
            cout<<"Where You want to Insert element at First Position or at last or anywhere according to order?[F/L/A]:";
            cin>>choice;
            if(is_Full(arr,sizeofarray)!=1){
            if(choice == 'F')
            {
                insert_First(arr,num,sizeofarray);
                cout<<"Number is inserted!\n";
                for(int i = 0; i<sizeofarray;i++)
                {
                    cout<<arr[i]<<"\t";
                }
            }
            if(choice == 'L')
            {
                insert_last(arr,num,sizeofarray);
                 cout<<"Number is inserted!\n";
                for(int i = 0; i<sizeofarray;i++)
                {
                    cout<<arr[i]<<"\t";
                }

            }
            if(choice == 'A')
            {
                insert_Any(arr,num,sizeofarray);
                 cout<<"Number is inserted!\n";
                for(int i = 0; i<sizeofarray;i++)
                {
                    cout<<arr[i]<<"\t";
                }

            }
            }
            else
            {
              cout<<"Array is Full of index plz Delete some Numbers!";
            }
          break;
          case 'D':
           {
            char choice;
            cout<<"Where You want to Delete element at First Position or at last or anywhere according to order?[F/L/A]:";
            cin>>choice;
            if(choice == 'F')
            {
                del_First(arr,sizeofarray);
                 cout<<"Number is Deleted!\n";
                for(int i = 0; i<sizeofarray;i++)
                {
                    cout<<arr[i]<<"\t";
                }

            }
            if(choice == 'L')
            {
                del_last(arr,sizeofarray);
                 cout<<"Number is Deleted!\n";
                for(int i = 0; i<sizeofarray;i++)
                {
                    cout<<arr[i]<<"\t";
                }

            }
            if(choice == 'A')
            {
                int ind;
                cout<<"Plz Enter Index of Number You Want to Delete:";
                cin>>ind;
                del_Any(arr,ind,sizeofarray);
                 cout<<"Number is Deleted!\n";
                for(int i = 0; i<sizeofarray;i++)
                {
                    cout<<arr[i]<<"\t";
                }

            }
            }
          break;
          default:
          cout<<"Enter Valid Choice!";
           }
        }
    return 0;
}
void insert_First(int arr[],int num,int sizeofarray)
{
    int temp;
    for(int i= sizeofarray - 1;i>0;i--)
    {
        temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
    }
    arr[0] = num;
}
void insert_last(int arr[],int num,int sizeofarray)
{
    if(arr[sizeofarray - 1]==0)
    {
    arr[sizeofarray - 1] = num;
    }
}
void insert_Any(int arr[],int num,int sizeofarray)
{
    if(arr[sizeofarray-1]==0)
    {
    int ind;
    for(int i = 0; i<sizeofarray; i++)
    {
        if(arr[i]>num)
        {
          ind = i;
        }
    }
    int temp;
    for(int i=sizeofarray - 1 ;i>ind;i--)
    {
        temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
    }
    arr[ind] = num;
    }
}
int is_Full(int arr[], int sizeofarray) {
    for (int i = 0; i < sizeofarray; i++) {
        if (arr[i] == 0) {
            return 0; // Array is not full if any element is 0
        }
    }
    return 1; // Array is full if no element is 0
}
void del_First(int arr[],int sizeofarray)
{
    int temp;
    arr[0] = 0;
    for(int i=0;i<sizeofarray-1;i++)
    {
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
}
void del_last(int arr[],int sizeofarray)
{
    if(arr[sizeofarray - 1]!=0)
    {
    arr[sizeofarray - 1] = 0;
    }
}
void del_Any(int arr[],int index,int sizeofarray)
{
    arr[index]=0;
    int temp = 0;
    for(int i=index ;i<sizeofarray-1;i++)
    {
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
}

