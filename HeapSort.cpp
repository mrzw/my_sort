//
// Created by zw on 18-4-7.
//

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &a, int n, int index) {
    int largestIndex = index;
    int left = 2*index+1;
    int right = 2*index+2;
    if(left<n && a[largestIndex]<a[left]) {
        largestIndex = left;
    }
    if(right<n && a[largestIndex]<a[right]) {
        largestIndex = right;
    }
    int temp;
    if(largestIndex!=index) {
        temp = a[largestIndex];
        a[largestIndex] = a[index];
        a[index] = temp;
        heapify(a, n, largestIndex);
    }
}
/*
 * 堆排序 时间复杂度O(nlogn), 不稳定
 */
void HeapSort(vector<int> &a, int n) {
    for(int i=n/2-1; i>=0; i--) {
        heapify(a, n, i);
    }
    int temp;
    for(int i=n-1; i>=0; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}
int main(int argc, char** argv) {
    vector<int> input = {64, 34, 25, 12, 22, 11, 90};
    HeapSort(input, input.size());
    for(auto i:input) {
        cout << i << " ";
    }
    cout << endl;
}