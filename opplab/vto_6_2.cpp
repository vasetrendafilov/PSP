#include "iostream"
#include "string"
using namespace std;

class Drink{
private:
  string name;
  int price;
  bool type;
public:
  Drink(string namev="",int pricev=0,bool typev = false)
  :name(namev),price(pricev),type(typev){}
  void operator = (const Drink &x){
    name = x.name;
    price = x.price;
    type = x.type;
  }
  friend ostream & operator << (ostream &out,const Drink &x);
  friend istream & operator >> (istream &in,Drink &x);
};
ostream & operator << (ostream &out,const Drink &x){
  out<<x.name<<" "<<x.price<<( x.type?" Alxoxolen":" Bezalxoxolen" )<<endl;
  return out;
}
istream & operator >> (istream &in,Drink &x){
  cout<<"Vnesi ime: ";
  in>>x.name;
  cout<<"Cena i type: ";
  in>>x.price>>x.type;
  return in;
}
class Storage{
private:
  int br;
  Drink *drinks;
public:
  Storage(){
    br = 1;
    drinks = new Drink[br];
  }
  Storage(int brv,Drink drink[]){
    br = brv;
    drinks = new Drink[br];
    for(int i=0;i<br;i++)
      drinks[i] = drink[i];
  }
  ~Storage(){delete [] drinks;}
  void add(Drink &x){
    Drink *temp = new Drink[br+1];//voa moze
    for(int i=0;i<br;i++)
      temp[i] = drinks[i];
    temp[br++] = x;
    delete [] drinks;
    drinks = temp;
  }
  friend ostream & operator <<(ostream &out,const Storage &x);
};
ostream & operator <<(ostream &out,const Storage &x){
  for(int i=0;i<x.br;i++)
    out<<x.drinks[i];
  return out;
}
int main(){
  Drink a[3],c;
  for(int i=0;i<2;i++)
    cin>>a[i];
  Storage b(3,a);
  cout<<b;
  cin>>c;
  b.add(c);
  cout<<b;
  return 0;
}
