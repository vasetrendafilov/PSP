#include "iostream"
#include "string"
#include "cstring"
using namespace std;

class Odmor{
protected:
  char *name;
  int days,price,br;
  int *prostorii;
public:
  Odmor(char *namev=NULL,int daysv=0,int pricev=0,int brv=0,int *pros = NULL)
  :days(daysv),price(pricev),br(brv){
    name = new char[strlen(namev)+1];
    strcpy(name,namev);
    prostorii = new int [br];
    for(int i=0;i<br;i++)
      prostorii[i] = pros[i];
  }
  Odmor(const Odmor &x):days(x.days),price(x.price),br(x.br){
    name = new char[strlen(x.name)+1];
    strcpy(name,x.name);
    prostorii = new int [br];
    for(int i=0;i<br;i++)
      prostorii[i] = x.prostorii[i];
  }
  virtual ~Odmor(){
    delete [] name;
    delete [] prostorii;
  }
  virtual int cena(){
    int temp=0;
    for(int i=0;i<br;i++) temp+= prostorii[i];
    return price + temp;
  }
  virtual void print(){
    cout<<name<<" "<<days<<" "<<endl;
    for(int i=0;i<br;i++) cout<<prostorii[i]<<" ";
  }
  bool operator < ( Odmor &x){ return (cena() < x.cena());}
};
class Leten:public Odmor{
protected:
  int type;
  bool pansion;
public:
  Leten(char *name=NULL,int days=0,int price=0,int br=0,int pros[]=NULL,int typev=0,bool pansionv = false)
  :Odmor(name,days,price,br,pros),type(typev),pansion(pansionv){}
  Leten(const Leten &x):Odmor(x),type(x.type),pansion(x.pansion){}
  int cena(){
    return Odmor::cena() + ((pansion)?150:100) + (type == 2)*100;
  }
  void print(){
    Odmor::print();
    cout<<"Cenata e "<<cena()<<endl;
  }
};
class Zimski:public Odmor{
protected:
  int karta;
  bool ski;
public:
  Zimski(char *name=NULL,int days=0,int price=0,int br=0,int pros[]=NULL,bool skiv = false,int kartav=0)
  :Odmor(name,days,price,br,pros),karta(kartav),ski(skiv){}
  Zimski(const Zimski &x):Odmor(x),karta(x.karta),ski(x.ski){}
  int cena(){
    int temp = 0;
    if(ski) temp = karta * days;
    return Odmor::cena() + temp;
  }
  void print(){
    Odmor::print();
    cout<<"cenata e "<<cena()<<endl;
  }
};
void max(Odmor **niz,int br){
  int n = 0;
  for(int i=0;i<br;i++)
    if(niz[n]->cena() < niz[i]->cena()) n=i;
  niz[n]->print();
}
int main()
{
  int a[] = {50,30,20,60};
  Odmor *odmori[3];
  odmori[0] = new Leten("Maldivi", 10, 1000, 4, a, 2);
  odmori[1] = new Zimski("Kopaonik", 7, 500, 3, {20, 25, 20}, true, 40);
  odmori[2] = new Leten("Santorini", 7, 700, 3, {10, 15, 30}, 2);
  max(odmori,3);
  return 0;
}
