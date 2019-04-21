#include "iostream"
using namespace std;

class Rational{
private:
  int num,den;
  int gcd(int m,int n){
    if(n==0)return m;
    return gcd(m,m%n);
  }
  void reduce(){
    int g = gcd(num,den);
    num /=g;
    den /=g;
  }
public:
  //Rational(int n=0,int d=1):num(n),den(d){} shorthend
  Rational (int num=0,int den = 1){
    this->num=num;
    this->den=den;
  }
  Rational(const Rational&r):num(r.num),den(r.den){
    cout<<"caled"<<endl;
  }
  void print(){cout<<num<<"/"<<den<<endl;}
};
int main(){
  Rational x(10,5);
  Rational y(x);
  cout << "x = ";
  x.print();
  cout<<" , y= ";
  y.print();
  return 0;
}
