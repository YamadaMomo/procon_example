#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long int ull;

vector<ull> rolling_hash(string s, int m){
  int n = s.length();
  if(n < m)return vector<ull>();
  vector<ull>rh(n - m + 1, 0);
  ull h_val = 0, base = 1e9 + 7, t = 1;
  for (int i = m - 1; i >= 0; i--) {
    h_val = t*s[i];
    t *= base;
  }
  for (int i = 0; i < n - m; i++) {
    rh[i] = h_val*base + s[i + m] - s[i]*t;
  }
  return rh;
}
