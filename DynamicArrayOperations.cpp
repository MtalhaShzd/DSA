#include<iostream>
using namespace std;
void insertArrayElements(int* array, int capacity);
void insertAtFirst(int*& array,int& capacity, int number);
void insertAtLast(int*& array,int& capacity, int number);
void insertAtPos(int*& array,int& capacity, int index,int number);
void deleteAtFirst(int*& array,int& capacity);
void deleteAtLast(int*& array,int& capacity);
void deleteAtPos(int*& array,int& capacity, int index);
void growArray(int*& array,int& capacity);
void shrinkArray(int*& array,int& capacity);
void printArray(int* array);
int size = 0;
int  main()
{
    int capacity;
    cout<<"Enter the capacity of Array:";
    cin>>capacity;
    int* array = new int[capacity];
    insertArrayElements(array,capacity);
    insertAtFirst(array,capacity,0);
    insertAtFirst(array,capacity,1);
    insertAtLast(array,capacity,2);
    insertAtLast(array,capacity,3);
    insertAtPos(array,capacity,3,0);
    deleteAtLast(array,capacity);
    deleteAtFirst(array,capacity);
    deleteAtPos(array,capacity,3);
    printArray(array);

}
void insertArrayElements(int* array, int capacity)
{

    for(int i = 0; i<capacity; i++)
    {
        cout<<"Enter Element\t"<<i+1<<"\tof Array:";
        cin>>array[i];
        size++;
    }
}
void insertAtFirst(int*& array,int& capacity, int number)
{
    if(capacity == size)
    {
        growArray(array,capacity);
    }
    for(int i = size; i>0 ;i--)
    {
        int temp = array[i];
        array[i] = array[i-1];
        array[i-1] = temp;
    }
    array[0] = number;
    size++;
}
void growArray(int*& array,int& capacity)
{
    int* temp = new int[capacity*2]();         //() is used  for value  initialization all values are set to zero
    capacity = capacity*2;
    for(int i = 0; i<size;i++)
    {
        temp[i] = array[i];
    }
    delete [] array;
    array = temp;
}
void printArray(int* array)
{
    for(int i = 0 ; i < size ; i++)
    {
        cout<<array[i]<<"\t"<<endl;
    }
}
void insertAtLast(int*& array,int& capacity, int number)
{
    if(capacity == size)
    {
        growArray(array,capacity);
    }
    array[size] = number;
    size++;
}
void insertAtPos(int*& array,int& capacity, int index, int number)
{
    if(capacity == size)
    {
        growArray(array,capacity);
    }
    for(int i = size; i>index ;i--)
    {
        int temp = array[i];
        array[i] = array[i-1];
        array[i-1] = temp;
    }
    array[index] = number;
    size++;
}
void shrinkArray(int*& array,int& capacity)
{
    capacity = size;
    int* temp = new int[capacity]();
    for(int i = 0; i<size; i++)
    {
        temp[i] = array[i];
    }
    delete [] array;
    array =  temp;
}
void deleteAtFirst(int*& array,int& capacity)
{
    array[0] = 0;
    for(int i = 0; i < size - 1 ; i++)
    {
        int temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
    }
    size--;
    if(size == (capacity/2))
    {
        shrinkArray(array,capacity);
    }
}
void deleteAtLast(int*& array,int& capacity)
{
    array[size] = 0;
    size--;
    if(size == (capacity/2))
    {
        shrinkArray(array,capacity);
    }
}
void deleteAtPos(int*& array,int& capacity,int index)
{
    array[index] = 0;
    for(int i = index; i < size - 1 ; i++)
    {
        int temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
    }
    size--;
   if(size == (capacity/2))
    {
        shrinkArray(array,capacity);
    }
}