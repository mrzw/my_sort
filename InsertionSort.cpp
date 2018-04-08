//
// Created by zw on 18-4-7.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * 插入排序 时间复杂度O(n2), 辅助空间O(1), 稳定
 */
void InsertionSort(vector<int> &a, int n) {
    int temp, j;
    for(int i=1; i<n; i++) {
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j]>temp) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}
int main(int argc, char** argv) {
    vector<int> input = {64, 34, 25, 12, 22, 11, 90};
    InsertionSort(input, input.size());
    for(auto i:input) {
        cout << i << " ";
    }
    cout << endl;
}