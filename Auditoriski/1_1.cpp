#include "iostream"
#include "math.h"

using namespace std;

struct Tocka {
  int x,y;
};
int dis(Tocka a,Tocka b){
  return sqrt( pow((a.x-b.x),2) + pow((a.y-b.y),2));
}
int par(Tocka a,Tocka b,Tocka c){
  return dis(a,b)+dis(b,c)+dis(c,a);
}
int main() {
  Tocka a = {3,0};
  Tocka b = {3,3};
  Tocka c = {0,0};
  cout << par(a,b,c) <<endl;
  return 0;
}
