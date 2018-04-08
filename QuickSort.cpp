//
// Created by zw on 18-4-7.
//

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &a, int low, int high) {
    int pivot = a[high];
    int temp;
    int i = low-1;
    for(int j=low; j<high; j++) {
        if(a[j]<=pivot) {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;
    return i+1;
}
/*
 * 快速排序 时间复杂度O(nlogn), 辅助空间O(1), 不稳定
 */
void QuickSort(vector<int> &a, int low, int high) {
    int index;
    if(low < high) {
        index = partition(a, low, high);
        QuickSort(a, low, index-1);
        QuickSort(a, index+1, high);
    }
}
int main(int argc, char** argv) {
    vector<int> input = {64, 34, 25, 12, 22, 11, 90};
    QuickSort(input, 0, input.size()-1);
    for(auto i:input) {
        cout << i << " ";
    }
    cout << endl;
}