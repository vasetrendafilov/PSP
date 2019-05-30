#include "iostream"
#include "string"
using namespace std;

class Odmor{
protected:
  string name;
  int days;
  float price;
public:
  Odmor(string namev="",float pricev=0,int daysv=0)
  :name(namev),price(pricev),days(daysv){}
  Odmor(const Odmor &x)
  :name(x.name),price(x.price),days(x.days){}
  bool poskap(Odmor &x){ return price>x.price;}
  float eu2mk(){return price*61.7;}
  void print(){ cout<<name<<" "<<eu2mk()<<endl;}
};
class Foo{
protected:
  Odmor *odmori;
  int br;
  float fkupno;
public:
  Foo(Odmor *odmoriv=NULL,int brv=0):br(brv),fkupno(0){
    odmori = new Odmor[br];
    for(int i=0;i<br;i++){
      fkupno += odmoriv[i].eu2mk();
      odmori[i] = odmoriv[i];
    }
  }
  Foo(const Foo &x):br(x.br),fkupno(x.fkupno){
    odmori = new Odmor[br];
    for(int i=0;i<br;i++){
      odmori[i] = x.odmori[i];
    }
  }
  ~Foo(){ delete [] odmori; }
  Odmor max(){
    int n=0;
    for(int i=0;i<br;i++)
      if(!odmori[n].poskap(odmori[i])) n=i;
    return odmori[n];
  }
  void fuc(){
    for(int i=0;i<br;i++)
      if(odmori[i].eu2mk() > fkupno/br) odmori[i].print();
  }
};
int main(){
  Odmor a[]={Odmor("MK",100,1),Odmor("UK",130,4),Odmor("LI",123,9)};
  Foo b(a,3);
  b.fuc();
  return 0;
}
