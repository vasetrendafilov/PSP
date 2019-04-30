#include <iostream>
#include "string"

using namespace std;

class foo{
private:
  int num;
public:
  foo(int n = 0):num(n){}
  foo operator +(foo a){
    return foo(num+a.num);
  }
  void print(){
    cout<<num<<endl;
  }
};

int main(){
  foo a(10);
  foo b(3);
  foo c;
  c = a + b;
  c.print();
}
