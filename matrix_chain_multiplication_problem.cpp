#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main(int argc, char *argv[]){
  int n;
  cin >> n;
  pii mat[n];
  int dp[n][n];
  int p[n + 1];

  //ここから
  for (int i = 0; i < n; i++) {
    cin >> mat[i].first >> mat[i].second;
  }
  for (int i = 0; i < n; i++) {
    p[i] = mat[i].first;
  }
  p[n] = mat[n - 1].second;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if(i != j)dp[i][j] = 1e9;
      else dp[i][j] = 0;
    }
  }
  //ここまで初期化

  //ここからDP
  for (int k = 1; k <= n; k++) {
    for (int i = 0; i <= n - k; i++) {
      for (int j = 1; j < k; j++) {
        int end = i + k - 1;
        std::cout << "i:" << i << " j:" << end << " mid:" << end - j << std::endl;
        dp[i][end] = max(dp[i][end], dp[i][end - j] + dp[end - j + 1][end]  + p[i]*p[i + j]*p[end + 1]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << dp[i][j] << " ";
    }
    std::cout << std::endl;
  }
  // for (int l = 2; l <= n; l++) {
  //   for (int i = 0; i <= n - l; i++) {
  //     int j = i + l - 1;
  //     for (int k = i; k < j; k++) {
  //       dp[i][j] = min(dp[i][j],
  //                      dp[i][k] + dp[k + 1][j] + p[i]*p[k + 1]*p[j + 1]);
                       
  //     }
  //   }
  // }
  std::cout << dp[0][n - 1] << std::endl;
            
  return 0;
}
