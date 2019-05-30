#include "iostream"
#include "string"
using namespace std;

class Kniga{
protected:
  string name,avtor;
  int sold,price;
public:
  Kniga(string namev="",string avtorv="",int pricev=0,int soldv=0)
  :name(namev),avtor(avtorv),price(pricev),sold(soldv){}
  Kniga(const Kniga &x)
  :name(x.name),avtor(x.avtor),price(x.price),sold(x.sold){}
  int zarabotka(){
    return price*sold;
  }
  friend ostream & operator << (ostream &out , const Kniga &x){
    return out<<x.name<<" "<<x.avtor<<" "<<x.price<<" "<<x.sold;
  }
};
class Strucna:public Kniga{
protected:
  int type;
public:
  Strucna(string name="",string avtor="",int price=0,int sold=0,int typev=0)
  :Kniga(name,avtor,price,sold),type(typev){}
  Strucna(const Strucna &x)
  :Kniga(x),type(x.type){}
  int zarabotka(){
    return Kniga::zarabotka() + type*10;
  }
  friend ostream & operator << (ostream &out , const Strucna &x){
    return out<<Kniga(x)<<" "<<x.type;///very nice
  }
};
int main(){
  Strucna a("naj","vase",100,2,1);
  cout<<a;
  return 0;
}
