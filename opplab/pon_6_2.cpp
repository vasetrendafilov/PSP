#include "iostream"
#include "string"
using namespace std;

class Farmerki{
private:
  string brend;
  int cena;
  bool pol;
public:
  Farmerki(string x="",int cenav=0,bool polv=false):brend(x),cena(cenav),pol(polv){}
  void operator = (const Farmerki &x){
    brend = x.brend;
    cena = x.cena;
    pol = x.pol;
  }
  friend ostream & operator << (ostream &out, const Farmerki &x);
};
ostream & operator << (ostream &out, const Farmerki &x){
  out<<"Brend/Pol: "<<x.brend<<" / "<<x.pol<<endl;
  out<<"Cena: "<<x.cena<<endl;
  return out;
}
class Butik{
private:
  Farmerki *far;
  int br;
public:
  Butik(){
    far = new Farmerki[1];
    far[0] = Farmerki();
    br=1;
  }
  Butik(Farmerki x[],int brv){
    br = brv;
    far = new Farmerki[br];
    for(int i=0;i<br;i++)
      far[i] = x[i];
  }
  ~Butik(){ delete [] far;}
  void add(Farmerki &f){
    Farmerki *temp;
    temp =  new Farmerki[++br];
    for(int i=0;i<br-1;i++)
      temp[i+1] = far[i];
    temp[0] = f;
    delete [] far;
    far = temp;
  }
  friend ostream & operator << (ostream &out,const Butik &x);
};
ostream & operator << (ostream &out,const Butik &x){
  for(int i=0;i<x.br;i++)
    out<<x.far[i];
  return out;
}
int main(){
  Farmerki a[2],d("kak",1002);
  a[0] = Farmerki("ka",100,true);
  a[1] = Farmerki();
  Butik c(a,2);
    cout<<c<<endl;
  c.add(d);
  cout<<c<<endl;
  return 0;
}
