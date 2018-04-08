//
// Created by zw on 18-4-7.
//

#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &a, int left, int middle, int right) {
    vector<int> L(middle-left+1);
    vector<int> R(right-middle);
    for(int i=0; i<middle-left+1; i++) {
        L[i] = a[left+i];
    }
    for(int j=0; j<right-middle; j++) {
        R[j] = a[middle+1+j];
    }
    int i=0,j=0,k=left;
    while(i<middle-left+1 && j<right-middle) {
        if(L[i]<=R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<middle-left+1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<right-middle) {
        a[k] = R[j];
        j++;
        k++;
    }
//    for(auto temp:a) {
//        cout << temp << " ";
//    }
//    cout << endl;
}
/*
 * 归并排序 时间复杂度O(nlogn), 辅助空间O(n), 稳定
 */
void MergeSort(vector<int> &a, int left, int right) {
    if(left<right) {
        int m = left + (right-left)/2;
        //cout << "left " << left << " m " << m << endl;
        MergeSort(a, left, m);
        //cout << "m+1 " << m+1 << " right " << right << endl;
        MergeSort(a, m+1, right);
        //cout << "left " << left << " m " << m << " right " << right << endl;
        Merge(a, left, m, right);
    }
}
int main(int argc, char** argv) {
    vector<int> input = {64, 34, 25, 12, 22, 11, 90};
    MergeSort(input, 0, input.size()-1);
    for(auto i:input) {
        cout << i << " ";
    }
    cout << endl;
}