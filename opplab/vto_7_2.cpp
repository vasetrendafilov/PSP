#include "iostream"
#include "string"
using namespace std;

class Delo{
protected:
  string name;
  float price;
public:
  Delo(string namev ="",float pricev =0)
  :name(namev),price(pricev){}
  Delo(const Delo &x):name(x.name),price(x.price){}
/*  Delo & operator =(const Delo &x){
    name = x.name;
    price = x.price;                    vakvo cudo so operatori ne
    return *this;
  }*/
  virtual float cena(){ return price;}
  virtual void print(){
    cout<<name<<" "<<cena();
  }
};
class Muzi:public Delo{
protected:
  int year;
public:
  Muzi(string name="",float price=0,int yearv=0)
  :Delo(name,price),year(yearv){}
  Muzi(const Muzi &x):Delo(x),year(x.year){}
  virtual float cena(){
    return (year == 17)*(0.1*price)+price;
  }
  virtual void print(){
    cout<<name<<" "<<year<<" "<<cena();
  }
};
class Sli:public Delo{
protected:
  int dmg;
public:
  Sli(string name="",float price=0,int dmgv=0)
  :Delo(name,price),dmg(dmgv){}
  Sli(const Sli &x):Delo(x),dmg(x.dmg){}
  virtual float cena(){
    return price/dmg;
  }
  virtual void print(){
    cout<<name<<" "<<dmg<<" "<<cena();
  }
};
void fja(Delo *niza[],int br){
  int max = 0;
  for(int i=0;i<br;i++)
    if(niza[max]->cena() < niza[i]->cena())
      max = i;
  niza[max]->print();
}
int main(){
  Delo *niza[20];
  Muzi m("m1",200,17);
  Sli sl1("sl1",300,1),sl2("sl1",400,40);
  niza[0]=&m;
  niza[1]=&sl1;
  niza[2]=&sl2;
  fja(niza,3);
  return 0;
}
