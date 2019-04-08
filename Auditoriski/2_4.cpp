#include "iostream"
#include "math.h"
#include "string"

using namespace std;

struct Tocka{
  int x,y;
};
struct Rect{
  int width;
  Tocka a;
  void init(int w,Tocka b);
  void print(){
    cout<<a.x<<" "<<a.y<<endl;
  }
};
void Rect::init(int w, Tocka b){
  width = w;
  a = b;
}
void shift(int x, int y, Rect &rec){
  rec.a.x += x;
  rec.a.y += y;
}
int main(){
  Tocka a = {0,1};
  Rect b;
  b.init(10,a);
  shift(3,1,b);
  b.print();
}
