#ifndef MAXHEAP_H_INCLUDED
#define MAXHEAP_H_INCLUDED
#include<vector>
#include<iostream>
#include "Heap.h"
template<class ItemType>
class MaxHeap : public Heap<ItemType>
{
    public:
    MaxHeap(int capacity=0);
    MaxHeap(const std::vector<ItemType>& existingItems);
    ~MaxHeap();
    bool IsHeap() override;
    void ReheapDown(int root, int bottom) override;
    void ReheapUp(int root, int bottom) override;
};
template<class ItemType>
MaxHeap<ItemType>::MaxHeap(int capacity)
    : Heap<ItemType>(capacity)
{
}
template<class ItemType>
MaxHeap<ItemType>::MaxHeap(const std::vector<ItemType>& existingItems)
    : Heap<ItemType>(existingItems)
{
}
template<class ItemType>
MaxHeap<ItemType>::~MaxHeap()
{
}
template<class ItemType>
bool SatisfiesHeapProperty(const std::vector<ItemType> elements
                           , int atIndex)
{
    if (atIndex < 0 || atIndex >= elements.size())
        return true;
    int parent = atIndex;
    int leftChild = (2 * parent) + 1;
    int rightChild = (2 * parent) + 2;
    int minChild = -1;
    if (leftChild < elements.size())
    {
        minChild = leftChild;
        if (rightChild < elements.size())
        {
            if (elements.at(minChild) > elements.at(rightChild))
                minChild = rightChild;
        }
        if (elements.at(parent) < elements.at(minChild))
            return false;
        return (SatisfiesHeapProperty(elements, leftChild)
                && SatisfiesHeapProperty(elements, rightChild));
    }
    return true;
}
template<class ItemType>
bool MaxHeap<ItemType>::IsHeap()
{
    int root = 0;
    return SatisfiesHeapProperty(this->elements, root);
}
template<class ItemType>
void MaxHeap<ItemType>::ReheapDown(int root, int bottom)
{
    int parent = root;
    int maxChild;
    int leftChild = (2 * parent + 1);
    int rightChild = (2 * parent + 2);
    if (leftChild <= bottom)
    {
        maxChild = leftChild;
        if (rightChild <= bottom)
        {
            if (this->elements[maxChild] < this->elements[rightChild])
                maxChild = rightChild;
        }
        if (this->elements[parent] < this->elements[maxChild])
        {
            Swap(this->elements[parent], this->elements[maxChild]);
            ReheapDown(maxChild, bottom);
        }
    }
}
template<class ItemType>
void MaxHeap<ItemType>::ReheapUp(int root, int bottom)
{
    int child = bottom;
    int parent = ((child - 1) / 2);
    if (child > root)
    {
        if (this->elements[parent] < this->elements[child])
        {
            Swap(this->elements[parent], this->elements[child]);
            ReheapUp(root, parent);
        }
    }
}


#endif // MAXHEAP_H_INCLUDED
