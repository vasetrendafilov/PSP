#include "iostream"
#include "math.h"
#include "string"

using namespace std;

struct Igrac{
  string ime,prezime;
  int golovi,poz;
  void print(){cout<<ime<<" "<<prezime<<" "<<golovi<<" "<<poz<<endl;}
  void init(string i,string p,int g,int h){
    ime = i;
    prezime = p;
    golovi = g;
    poz = h;
  }
};
struct Rep{
  string ime;
  int golovi;
  Igrac igraci[2];
  void init(string a,Igrac x[]);
  void calcGolovi();
  Igrac getByPoz(int poz);
};
void Rep::init(string a,Igrac x[]){
  golovi = 0;
  ime = a;
  for (int i = 0; i < 2; i++) {
    igraci[i]=x[i];
    golovi += x[i].golovi;
  }
}
Igrac Rep::getByPoz(int poz){
  for (size_t i = 0; i < 2; i++)
    if(igraci[i].poz == poz) return igraci[i];
  return {};
}
void naj(Rep x[]){
  Igrac naj[2];
  naj[0] = x[0].getByPoz(1);
  naj[1] = x[0].getByPoz(2);
  for (int i = 0; i < 2/*br na mesta*/; i++) {
    for (size_t j = 0; j < 2/*br na rep*/; j++) {
      if(naj[i].golovi < x[j].getByPoz(i+1).golovi)
        naj[i] = x[j].getByPoz(i+1);
    }
  }
  for (size_t i = 0; i < 2; i++) {
    naj[i].print();
  }
}
int main(){
  Rep x[2];
  Igrac a[2];
  a[0].init("vase","das",10,1);
  a[1].init("bojan","Sda",4,2);
  Igrac b[2];
  b[0].init("drds","das",5,1);
  b[1].init("dd","Sda",9,2);
  x[0].init("mak",a);
  x[1].init("va",b);
  naj(x);
  return 0;
}
