#include "Heap.h"

template<class ItemType>
Heap<ItemType>::Heap(int capacity)
{
    if (capacity > 0)
        elements.reserve(capacity);
    else
        elements.reserve(100);
}
template<class ItemType>
Heap<ItemType>::Heap(const std::vector<ItemType>& existingItems)
{
    Reset(existingItems);
}
template<class ItemType>
Heap<ItemType>::~Heap()
{
    MakeEmpty();
}
template<class ItemType>
void Swap(ItemType& first, ItemType& second)
{
    ItemType temp = first;
    first = second;
    second = temp;
}
template<class ItemType>
void Heap<ItemType>::Insert(ItemType val)
{
    if (!IsHeap())
        Heapify();
    elements.push_back(val);
    int root = 0;
    int bottom = elements.size() - 1;
    ReheapUp(root, bottom);
}
template<class ItemType>
void Heap<ItemType>::MakeEmpty()
{
    elements.clear();
}
template<class ItemType>
void Heap<ItemType>::Reset(const std::vector<ItemType>& existingItems)
{
    MakeEmpty();
    for (const ItemType& item : existingItems)
        elements.push_back(item);
}
template<class ItemType>
int Heap<ItemType>::ExtractRoot()
{
    if (!IsHeap)
        Heapify();
    int root = 0;
    int bottom = elements.size() - 1;
    int maxItem = elements.at(root);
    swap(elements.at(root), elements.at(bottom));
    elements.pop_back();
    bottom = elements.size() - 1;
    ReheapDown(root, bottom);
    return maxItem;
}
template<class ItemType>
void Heap<ItemType>::Heapify()
{
    int lastParent = (elements.size() / 2);
    int root = 0;
    int bottom = elements.size() - 1;
    for (int subTreeRoot = lastParent
                           ; subTreeRoot >= root
            ; subTreeRoot--)
    {
        ReheapDown(subTreeRoot, bottom);
    }
}
template<class ItemType>
void Heap<ItemType>::HeapSort()
{
//This does inplace heapsort and
//store sorted values in the underlying vector
    if (!IsHeap)
        Heapify();
    int root = 0;
    for (int bottom = elements.size() - 1;
            bottom > root;
            bottom--)
    {
        int maxItem = elements.at(root);
        swap(elements.at(root), elements.at(bottom));
        int newBottom = bottom - 1;
        ReheapDown(root, newBottom);
    }
}
