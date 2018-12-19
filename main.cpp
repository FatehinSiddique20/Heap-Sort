#include <iostream>
#include "MaxHeap.h"
//#include "Heap.h"

using namespace std;

int main()
{
    vector<int> a(8);
    a[0]=14;
    a[1]=33;
    a[2]=27;
    a[3]=10;
    a[4]=35;
    a[5]=19;
    a[6]=48;
    a[7]=44;
    MaxHeap<int> h(a);
    h.HeapSort();
    h.Min();
    cout<<endl;
    h.Max();
    return 0;
}
