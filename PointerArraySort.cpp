#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {1,2,0,3,4};
    int *ptr_arr[5];
    int *temp;
    for(int i = 0; i<5 ; i++)
    {
        ptr_arr[i] = &arr[i];
    }
    for(int i =0;i<5;i++)
    {
        for(int j = i + 1 ;j<5;j++)
        {
        if(*ptr_arr[i]<*ptr_arr[j])
        {
           temp = ptr_arr[i];
           ptr_arr[i] = ptr_arr[j];
           ptr_arr[j] = temp;
        }
    }
    }
    for(int i = 0; i<5 ; i++)
    {
        cout<<*ptr_arr[i]<<"\t";
    }
return 0;
}