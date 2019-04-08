#include "iostream"
#include "math.h"

using namespace std;

struct Comp {
  int r,i;
  void print() {
    char znak = i<0?'-':'+';
    cout << r <<znak<<"j"<<abs(i)<<endl;
  }
};
Comp add(Comp a,Comp b){
  Comp c = {a.r+b.r,a.i+b.i};
  return c;
}
Comp sub(Comp a,Comp b){
  Comp c = {a.r-b.r,a.i-b.i};
  return c;
}
Comp multi(Comp a,Comp b){
  Comp c = {a.r*b.r - a.i * b.i,a.r*b.i + a.i*b.r};
  return c;
}
int main() {
  Comp a = {3,1};
  Comp b = {3,3};
  Comp c = {2,3};
  Comp x = multi(a,b);
  x.print();
  return 0;
}
