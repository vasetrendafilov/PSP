#include <iostream>
#include <string>
using namespace std;

class F2;//mora prototip za friend ja F1
class F1{
private:
  int a,b;
public:
  F1(int i=0,int j=0):a(i),b(j){}
  friend int sum(const F1 &x,const F2 &y);//globalna funkcija  F1 i F2
  void odzemi(const F2 &x);//mthod za F1
  friend class F3;// koneceija so klasa F3 ja ima F1
  void test(const F3 &x){cout<<x.a<<endl;}
};

class F2{
private:
  int a,b;
public:
  F2(int i=0,int j=0):a(i),b(j){}
  friend int sum(const F1 &x,const F2 &y);//globalna funkcija F1 i F2
  friend void F1::odzemi(const F2 &x);//mthod za F1
};

class F3{
private:
  int a,b;
public:
  F3(int i=0,int j=0):a(i),b(j){}
  int pom(const F1 &x){return a*x.a;}// koneceija so klasa F3 ja ima F1
};

int sum(const F1 &x,const F2 &y){
  return x.a+y.a;
}
void F1::odzemi(const F2 &x){
  cout<<a-x.a<<endl;
}
int main(){
  F1 a(5,10);
  F2 b(1,4);
  F3 c(2,6);
  cout<<sum(a,b)<<endl;
  a.odzemi(b);
  cout<<c.pom(a)<<endl;
  return 0;
}
