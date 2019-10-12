// **************************************************************************
//  File       [sort_tool.h]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The header file for the SortTool Class]
//  Modify     [2019/9/6 Cheng-Yun Hsieh]
// **************************************************************************

#ifndef _SORT_TOOL_H
#define _SORT_TOOL_H

#include<vector>
using namespace std;

class SortTool {
    public:
                    SortTool(); // constructor
        void        InsertionSort(vector<int>&); // sort data using insertion sort
        void        MergeSort(vector<int>&); // sort data using merge sort
        void        QuickSort(vector<int>&); // sort data using quick sort
        void        HeapSort(vector<int>&); // sort data using heap sort
    private:
        void        QuickSortSubVector(vector<int>&, int, int); // QS: quick sort subvector
        int         Partition(vector<int>&, int, int); // QS: partition the subvector
        void        MergeSortSubVector(vector<int>&, int, int); // MS: merge sort subvector
        void        Merge(vector<int>&, int, int, int); // MS: merge two sorted subvector
        void        MaxHeapify(vector<int>&, int); // HS: make tree with given root be a max-heap
                                                    //if both right and left sub-tree are max-heap
        void        BuildMaxHeap(vector<int>&); // HS: make data become a max-heap
        int         heapSize; // HS: heap size used in heap sort

};

#endif
