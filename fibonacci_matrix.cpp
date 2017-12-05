#include<iostream>
#include<vector>
using namespace std;
typedef long long int lli;

template<typename T>
class  matrix{
public:
  matrix(){};
  matrix(int h, int w){Init(h, w);}
  void Print();
  void Init(int h, int w);
  int Hight(){return h;}
  int Width(){return w;}
  matrix<T>  operator+(const matrix<T> m);
  matrix<T>  operator*(const matrix<T> m);
  matrix<T>  operator%(const int a);
  vector<T>& operator[](int i);
  void       operator=(const matrix<T>& m);
  void       operator%=(const int a);
private:
  int h = -1, w = -1;//h is row, w is collum
  vector<vector<T> > mat;
};

template<typename T>
void matrix<T>::
Print(){
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      std::cout << mat[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

template<typename T>
void matrix<T>::
Init(int _h, int _w){
  h = _h; w = _w;
  mat.resize(h);
  for(int i = 0; i < h; i++)
    mat[i].resize(w);
}

template<typename T>
matrix<T> matrix<T>::
operator+(const matrix<T> m){
  if(h == -1 and w == -1){
    Init(m.h, m.w);
  }
  if(h != m.h || w != m.w){
    cerr << "bug +" << endl;
    cerr << "  h:" << h   << "   w:" <<   w << endl;
    cerr << "m.h:" << m.h << " m.w:" << m.w << endl;
    exit(1);
  }
  matrix<T> res(h, w);
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      res[i][j] = mat[i][j] + m.mat[i][j];
    }
  }
  return res;
}

template<typename T>
matrix<T> matrix<T>::
operator*(const matrix<T> m){
  if(w != m.h){
    cerr << "bug *" << endl;
    cerr << "  h:" << h   << "   w:" <<   w << endl;
    cerr << "m.h:" << m.h << " m.w:" << m.w << endl;
    exit(1);
  }
  matrix<T> res(h, m.w);
  for(int i = 0; i < h; i++){
    for(int k = 0; k < m.w; k++){
      for(int j = 0; j < m.h; j++){
        res[i][k] = res[i][k] + (mat[i][j] * m.mat[j][k]);
      }
    }
  }
  return res;
}

template<typename T>
vector<T>& matrix<T>::
operator[](int i){
  return mat[i];
}

template<typename T>
void matrix<T>::
operator=(const matrix<T>& m){
  if(h == -1 and w == -1){
    Init(m.h, m.w);
  }
  if(h != m.h || w != m.w){
    cerr << "bug =" << endl;
    cerr << "  h:" << h   << "   w:" <<   w << endl;
    cerr << "m.h:" << m.h << " m.w:" << m.w << endl;
    exit(1);
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      mat[i][j] = m.mat[i][j];
    }
  }
}

template<typename T>
void matrix<T>::
operator%=(const int a){
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      mat[i][j] = mat[i][j]%a;
    }
  }
}


template<typename T>
matrix<T> matrix<T>::
operator%(const int a){
  matrix<T> res(h, w);
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      res[i][j] = mat[i][j]%a;
    }
  }
  return res;
}


int main(){
  lli n;
  std::cin >> n;
  matrix<lli> mat(2, 2), ans(2, 2);
  int a[2][2] = {{1, 0},
                 {1, 0}};
  mat[0][0] = 1;
  mat[0][1] = 1;
  mat[1][0] = 1;
  mat[1][1] = 0;
  ans = mat;
  while(n > 0){
    if(n > 1)ans = ans*ans;
    if(n&1)ans = ans*mat;
    n /= 2;
  }
  ans.Print();
  std::cout << ans[0][0] + ans[0][1] << std::endl;
  return 0;
}
