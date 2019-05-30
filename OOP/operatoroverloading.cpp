#include <iostream>
#include "string"

using namespace std;

class foo{
private:
  int num;
public:
  foo(int n = 0):num(n){}
  foo operator +(const foo a){
    return foo(num+a.num);
  }
  foo operator +(int a){
    return foo(num+a);
  }
  foo & operator ++(){//pred object
    num++;
    return *this;
  }
  foo operator ++(int){
    num++;
    return *this;
  }
  void print(){
    cout<<num<<endl;
  }
};

int main(){
  foo a(10);
  foo b(3);
  foo c;
  c = a + b + 6;
  ++c;
  c.print();
}
