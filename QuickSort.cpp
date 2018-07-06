//
// Created by zw on 18-4-7.
//

#include <iostream>
#include <vector>
using namespace std;

int partion(vector<int>& a, int start, int end) {
	int pivot = a[start];
	while(start < end) {
		while(start<end && a[end]>=pivot) --end;
		swap(a[start],a[end]);
		while(start<end && a[start]<=pivot) ++start;
		swap(a[start],a[end]);
	}
	return start;
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
