#include "iostream"
#include "string"
#include "cstring"
using namespace std;

class Delo{
protected:
  char *name;
  float price;
public:
  Delo(float pricev=0,char *namev = NULL):price(pricev){
    if(namev == NULL || namev == ""){
      name = new char[15];
      strcpy(name,"Nepoznat avtor");
    }else{
      name = new char[strlen(namev)+1];
      strcpy(name,namev);
    }
  }
  Delo(const Delo &x):price(x.price){
    name = new char[strlen(x.name)+1];
    strcpy(name,x.name);
  }
  ~Delo(){ delete [] name;}
  virtual float cena(){ return price;}
  virtual void print(){
    cout<<name<<" ";
  }
};
class Muz:public Delo{
protected:
  int year;
public:
  Muz(float price=0,int yearv=0,char *name = NULL)
  :Delo(price,name),year(yearv){}
  Muz(const Muz &x):Delo(x),year(x.year){}
  float cena(){
    return price + 0.1 * price * (year >= 1600 && year < 1700);
  }
  void print(){
    Delo::print();
    cout<<cena();
  }
};
class Sik:public Delo{
protected:
  int dmg;
public:
  Sik(float price=0,int dmgv=0,char *name = NULL)
  :Delo(price,name),dmg(dmgv){}
  Sik(const Sik &x):Delo(x),dmg(x.dmg){}
  float cena(){
    return price - (float)dmg/100 * price;
  }
  void print(){
    Delo::print();
    cout<<cena();
  }
};
void max(Delo *niz[],int br){
  int n=0;
  for(int i=1;i<br;i++)
    if(niz[n]->cena() < niz[i]->cena()) n=i;
  niz[n]->print();
}
int main(){
 Delo *a[10];
 char g[] = {'a','s','s','\0'};
 Sik b(100,10,g),c(1000,40,g);
 Muz d(100,1650,g);
 a[0] = &b;
 a[1] = &c;
 a[2] = &d;
 max(a,3);
  return 0;
}
