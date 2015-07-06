#include<bits/stdc++.h>
using namespace std;

vector<long long int> fibonatti;
int calc(int n){
  if(n <= 1)return 1;
  fibonatti[n] = calc(n - 1) + calc(n - 2);
  return fibonatti[n];
}

int main(int argc, char *argv[]){
  int n;
  cin >> n;
  fibonatti.resize(n + 1);
  fibonatti[0] = fibonatti[1] = 1;
  std::cout << calc(n) << std::endl;
  return 0;
}

