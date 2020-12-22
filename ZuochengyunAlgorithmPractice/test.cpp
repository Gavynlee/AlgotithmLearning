//
// Created by Gavyn on 2020/12/21.
//

#include<iostream>

#define length 5
using namespace std;

void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;

}
void heapinsert(int arr[],int index)
{
    while(arr[index] > arr[(index-1)/2])
    {
        swap(arr[index],arr[(index-1)/2]);
        index = (index-1)/2;
    }
}

int main()
{
    //int arr[length] = {2,1,3,6,0,4};
    int arr[length] = {3,4,5,1,2};
    int heapsize = length;
    for(int i = 0;i < heapsize;i++ )
    {
        heapinsert(arr,i);//用for循环传入要处理的index
    }

    system("pause");
    return 0;
}
