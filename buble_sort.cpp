#include<iostream>
using namespace std;

void bubleSort(int* A, int N){
  bool flag = 1;
  while(flag){
    flag = 0;    
    for (int i = 0; i < N; i++) {
      for (int j = N - 1; j >= i; j--) {
        if(A[j] < A[j - 1]){
          flag = 1;
          int tmp = A[j];
          A[j] = A[j - 1];
          A[j - 1] = tmp;
        }
      }
    }
  }
}
