#include "iostream"
#include "string"
using namespace std;

class Cake{
protected:
  string name;
  int price;
public:
  Cake(string namev="",int pricev=0)
  :name(namev),price(pricev){}
  Cake(const Cake &x)
  :name(x.name),price(x.price){}
  virtual int cena() = 0;
  virtual int dobivka()=0;
  virtual void print(){
    cout<<name<<" "<<price;
  }
};
class Sweet:public Cake{
protected:
  int sold;
public:
  Sweet(string name="",int price=0,int soldv=0)
  :Cake(name,price),sold(soldv){}
  Sweet(const Sweet &x):Cake(x),sold(x.sold){}
  virtual int cena(){
    return price - sold*2*(sold*2 < price/3);
  }
  int dobivka(){
    int temp=0;
    for(int i = cena();i<price;i++) temp+= i;
    return temp;
  }
  void print(){
    Cake::print();
    cout<<" Dobivka: "<<dobivka();
  }
};
class Salt:public Cake{
protected:
  int sold;
public:
  Salt(string name="",int price=0,int soldv=0)
  :Cake(name,price),sold(soldv){}
  Salt(const Salt &x):Cake(x),sold(x.sold){}
  virtual int cena(){
    return price - sold*(sold < price/2);
  }
  int dobivka(){
    int temp=0;
    for(int i = cena();i<price;i++) temp+= i;
    return temp;
  }
  void print(){
    Cake::print();
    cout<<" Dobivka: "<<dobivka();
  }
};
void max(Cake *niz[],int br){
  int n = 0;
  for(int i=1;i<br;i++)
    if(niz[n]->dobivka() < niz[i]->dobivka())
      n=i;
  niz[n]->print();    
}
int main(){
  Cake *a[3];
  Sweet b("naj",100,5);
  Salt c("sad",123,20),d("dsa",102,32);
  a[0] = &b;
  a[1] = &c;
  a[2] = &d;
  max(a,3);
}
