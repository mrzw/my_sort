//
// Created by zw on 18-4-7.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * 选择排序 时间复杂度O(n2), 辅助空间O(1), 不稳定
 */
void SelectionSort(vector<int> &a, int n) {
    int temp, minIndex;
    for(int i=0; i<n-1; i++) {
        minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(a[minIndex]>a[j]) {
                minIndex = j;
            }
        }
        if(minIndex!=i) {
            temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}
int main(int argc, char** argv) {
    vector<int> input = {64, 34, 25, 12, 22, 11, 90};
    SelectionSort(input, input.size());
    for(auto i:input) {
        cout << i << " ";
    }
    cout << endl;
}