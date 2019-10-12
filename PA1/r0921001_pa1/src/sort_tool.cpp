// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2019/9/6 Cheng-Yun Hsieh]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>
#include <limits>

// Constructor
SortTool::SortTool() {}


/* ---------------------- */
/* Insertsion sort method */
/* ---------------------- */
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    for ( unsigned i = 1; i<data.size() ; i++ ){
      int key = data[i];
      int j = i-1;
      while((j>=0) && (data[j]>key)){
        data[j+1] = data[j];
        j--;
      }
      data[j+1] = key;
    }
}


/* ----------------- */
/* Quick sort method */
/* ----------------- */
void SortTool::QuickSort(vector<int>& data){
    QuickSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high) {
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    if (low < high){
      int q = Partition(data, low, high);
      //cout<<low<<q<<high<<endl;
      QuickSortSubVector(data, low, q);
      QuickSortSubVector(data, q+1, high);
    }
}

// Partition
int SortTool::Partition(vector<int>& data, int low, int high) {
    // Function : Partition the vector
    // TODO : Please complete the function
    int key = data[low];
    int i = low - 1 ;
    int j = high + 1 ;
    while(1){
      while(1) {--j; if(data[j]<=key) break;}
      while(1) {++i; if(data[i]>=key) break;}
      if( i<j ){
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
      else return j;
    }
}


/* ----------------- */
/* Merge sort method */
/* ----------------- */
void SortTool::MergeSort(vector<int>& data){
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int>& data, int low, int high) {
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    if( low < high ){
      int mid = (high + low)/2;
      MergeSortSubVector(data, low, mid);
      MergeSortSubVector(data, mid+1, high);
      Merge(data, low, mid, high);
    }
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    int len_low = middle - low + 1;
    int len_high = high - middle;
    int data_low[len_low+1];
    int data_high[len_high+1];
    for (int i = 0; i<len_low; i++) data_low[i] = data[low+i];
    for (int i = 0; i<len_high; i++) data_high[i] = data[middle+1+i];
    data_low[len_low] = numeric_limits<int>::max();
    data_high[len_high] = numeric_limits<int>::max();
    int i=0;
    int j=0;
    for (int k=low; k<=high; k++){
      if (data_low[i] <= data_high[j]){
        data[k] = data_low[i];
        ++i;
      }
      else{
        data[k] = data_high[j];
        ++j;
      }
    }
}


/* ---------------- */
/* Heap sort method */
/* ---------------- */
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0],data[i]);
        heapSize--;
        MaxHeapify(data,0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
    int left_idx = root*2+1;
    int right_idx = root*2+2;
    int largest_idx = root;
    if ((left_idx<heapSize)&&(data[left_idx] > data[largest_idx])) largest_idx = left_idx;
    if ((right_idx<heapSize)&&(data[right_idx] > data[largest_idx])) largest_idx = right_idx;
    if (largest_idx != root) {
      swap(data[root],data[largest_idx]);
      MaxHeapify(data, largest_idx);
    }
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here
    for (int i = heapSize/2 -1; i>=0; i--) MaxHeapify(data,i);
}
