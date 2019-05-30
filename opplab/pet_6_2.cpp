#include "iostream"
#include "string"
using namespace std;
class Foo{
private:
  string *drinks;
  int br;
public:
  Foo(string *drinksv = NULL,int brv = 1):br(brv){
    drinks = new string[br];
    for(int i=0;i<br;i++) drinks[i] = drinksv[i];
  }
  Foo(const Foo &x):br(x.br){
    drinks = new string[br];
    for(int i=0;i<br;i++) drinks[i] = x.drinks[i];
  }
  ~Foo(){delete [] drinks;}
  Foo & operator = (const Foo &x){
    if(this == &x) return *this;
    br = x.br;
    delete [] drinks;
    drinks = new string[br];
    for(int i=0;i<br;i++) drinks[i] = x.drinks[i];
    return *this;
  }
  Foo & operator +=(string drink){
    string *temp = new string[br+1];
    for(int i=0;i<br;i++) temp[i] = drinks[i];
    temp[br++] = drink;
    delete [] drinks;
    drinks = temp;
    return *this;
  }
  friend ostream & operator <<(ostream &out,const Foo &x){
    for(int i=0;i<x.br;i++)out<<x.drinks[i]<<" ";
    return out;
  }
  Foo & operator --(int){
    string *temp = new string[--br];
    for(int i=0;i<br;i++) temp[i] = drinks[i+1];
    delete []drinks;
    drinks = temp;
    return *this;
  }
  string &operator [](int i){ return drinks[i];}
  const string &operator [](int i)const{ return drinks[i];}
};
int main(){
  string drinks[] = {"konjak","votka","peksi"};
  Foo a(drinks,3);
  const Foo b(drinks,2);
  a+="kokakola";
  a--;
  cout<<b[1];
  return 0;
}
