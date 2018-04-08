//
// Created by zw on 18-4-8.
//

#include <iostream>
#include <vector>
using namespace std;

int maxArray(const vector<int> &a, int n) {
    int max = a[0];
    for(int i=1; i<n; i++) {
        if(a[i]>max) {
            max = a[i];
        }
    }
    return max;
}
void countSort(vector<int> &a, int n, int exp) {
    vector<int> count(10);
    vector<int> output(n);
    for(int i=0; i<n; i++) {
        count[(a[i]/exp)%10]++;
    }
    for(int i=1; i<10; i++) {
        count[i] += count[i-1];
    }
    for(int i=n-1; i>=0; i--) {
        output[count[(a[i]/exp)%10]-1] = a[i];
        count[(a[i]/exp)%10]--;
    }
    for(int i=0; i<n; i++) {
        a[i] = output[i];
    }
}
/*
 * 基数排序, 稳定
 */
void RadixSort(vector<int> &a, int n) {
    int maxNum = maxArray(a, n);
    for(int i=1; maxNum/i>0; i*=10) {
        countSort(a, n, i);
    }
}
int main(int argc, char** argv) {
    vector<int> input = {64, 34, 25, 12, 22, 11, 90};
    RadixSort(input, input.size());
    for(auto i:input) {
        cout << i << " ";
    }
    cout << endl;
}