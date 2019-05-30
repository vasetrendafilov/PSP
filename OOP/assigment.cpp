#include "iostream"
#include "string"
using namespace std;

class foo{
private:
  int num;
public:
  foo(int n = 0):num(n){}

  foo & operator = (const foo &x)
  {
    if(this == &x) return *this;
    num = x.num;
    return *this;
  }
  friend ostream & operator << (ostream &out , const foo &x);
};
ostream & operator << (ostream &out, const foo &x){
  out<<x.num;
  return out;
}
int main(){
  foo a(10),b,c;
  c = b = a;
  a = a;
  cout<<a<<" "<<b<<" "<<c<<endl;
  return 0;
}
