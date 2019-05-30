#include "iostream"
#include "string"
#include "cstring"
using namespace std;

class Foo{
protected:
  char *type;
  int price;
public:
  Foo(char *typev = NULL,int pricev=0):price(pricev){
    type = new char[strlen(typev)+1];
    strcpy(type,typev);
  }
  Foo(const Foo &x):price(x.price){
    type = new char [strlen(x.type)+1];
    strcpy(type,x.type);
  }
  virtual int cena()=0;
  virtual void print(){
    cout<<type<<" ";
  }
};
class Boo:public Foo{
protected:
  int year;
  bool dali;
public:
  Boo(char *type=NULL,int price=0,int yearv=0,bool daliv=false)
  :Foo(type,price),year(yearv),dali(daliv){}
  Boo(const Boo &x):Foo(x),year(x.year),dali(x.dali){}
  int cena(){
    return price + dali*price/2;
  }
  void print(){
    Foo::print();
    cout<<year<<" "<<cena();
  }
};
class Goo:public Foo{
protected:
  bool dali;
public:
  Goo(char *type=NULL,int price=0,bool daliv=false)
  :Foo(type,price),dali(daliv){}
  Goo(const Goo &x):Foo(x),dali(x.dali){}
  int cena(){
    return price - (!dali)*price/2;
  }
  void print(){
    Foo::print();
    cout<<cena();
  }
};
void max(Foo *niz[],int br){
  int n=0;
  for(int i=1;i<br;i++)
    if(niz[n]->cena()<niz[i]->cena())n=i;
  niz[n]->print();  
}
int main(){
  Foo *a[10];
  Boo b("vase",1200,20,1),c("vds",500,23);
  Goo d("sad",2000),f("fsdfs",1000,1);
  a[0]=&b;
  a[1]=&c;
  a[2]=&d;
  a[3]=&f;
  max(a,4);
  return 0;
}
