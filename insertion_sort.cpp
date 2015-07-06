#include<iostream>
using namespace std;

void insertionSort(int* A, int N){//N個の要素を含む配列A
  for (int i = 1; i < N; i++) {
    int v = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j + 1] = A[j];j--;
      A[j + 1] = v;
    }
  }
}
