//
// Created by zw on 18-4-7.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * 冒泡排序 最坏时间复杂度O(n2), 最好时间复杂度O(n), 辅助空间O(1), 稳定
 */
void BubbleSort(vector<int> &a, int n) {
    int temp;
    bool flag;
    for(int i=0; i<n-1; i++) {
        flag = false;
        for(int j=0; j<n-i-1; j++) {
            if(a[j]>a[j+1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = true;
            }
        }
        if(flag==false){
            break;
        }
    }
}
int main(int argc, char** argv) {
    vector<int> input = {64, 34, 25, 12, 22, 11, 90};
    BubbleSort(input, input.size());
    for(auto &i:input) {
        cout << i << " ";
    }
    cout << endl;
}