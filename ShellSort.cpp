//
// Created by zw on 18-4-8.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * 希尔排序 时间复杂度O(n^1.3), 不稳定
 */
void ShellSort(vector<int> &a, int n) {
    for(int gap=n/2; gap>0; gap/=2) {
        for(int i=gap; i<n; i++) {
            int temp = a[i];
            int j;
            for(j=i; j>=gap && a[j-gap]>temp; j-=gap) {
                a[j] = a[j-gap];
            }
            a[j] = temp;
        }
    }
}
int main(int argc, char** argv) {
    vector<int> input = {64, 34, 25, 12, 22, 11, 90};
    ShellSort(input, input.size());
    for(auto i:input) {
        cout << i << " ";
    }
    cout << endl;
}