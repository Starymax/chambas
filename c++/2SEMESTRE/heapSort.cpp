#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int array[], int sizeHeap, int parentIndex){
    int larger = parentIndex;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;
    if(leftChildIndex < sizeHeap && array[leftChildIndex] > array[larger])
        larger = leftChildIndex;
    if(rightChildIndex < sizeHeap && array[rightChildIndex] > array[larger])
        larger = rightChildIndex;
    if(larger != parentIndex){
        swap(array[parentIndex], array[larger]);
        heapify(array, sizeHeap, larger);
    } 
}

void heapSort(int array[], int sizeArray){
    for (int nonleafNodeIndex = sizeArray / 2 - 1; nonleafNodeIndex >= 0; nonleafNodeIndex--)
        heapify(array, sizeArray, nonleafNodeIndex);
    for (int lastHeapIndex = sizeArray - 1; lastHeapIndex >= 1; lastHeapIndex--){
        swap (array[0], array[lastHeapIndex]);
        heapify(array, lastHeapIndex, 0);
    }
}

int main(){
    int array[] = {77, 15, 91, 21, 6, 46};
    int sizeArray = sizeof(array) / sizeof(array[0]);
    heapSort(array, sizeArray);
    for (int i = 0; i < sizeArray; i++)
        cout << array[i] << " ";
    getchar();
    return 0;
}