#include<bits/stdc++.h>
using namespace std;

struct graph{
public:
  vector<vector<int> > g;
  graph(int n){
    g.resize(n);
    for (int i = 0; i < n; i++) {
      g[i].resize(n);      
    }
};

int main(int argc, char *argv[]){
  graph g(10);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      g[i][j] = 10;
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      std::cout << g[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
 
