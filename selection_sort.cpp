#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char *argv[]){
  int a[n];
  sort(a, a + n);
  return 0;
}

void selectionSort(int* A, int N){
  for (int i = 0; i < N; i++) {
    int minj = A[i];
    int pos = i;
    for (int j = i; j < N; j++) {
      if(minj > A[j]){
        minj = A[j];
        pos = j;
      }
    }
    int tmp = A[i];
    A[i] = minj;
    A[pos] = tmp;
  }
}
