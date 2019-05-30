#include "iostream"
#include "string"
using namespace std;
class Foo{
protected:
  string name;
  int weight;
  bool type;
public:
  Foo(string namev="",int weightv=0,bool typev=false)
  :name(namev),weight(weightv),type(typev){}
  Foo(const Foo &x):name(x.name),weight(x.weight),type(x.type){}
  int cena(){ return 500+20*weight;}
  friend ostream & operator <<(ostream &out , const Foo &x){
    return out<<x.name<<" "<<x.weight<<" "<<x.type;
  }
};
class Boo:public Foo{
protected:
  bool proc;
public:
  Boo(string name="",int wight=0,bool type=false,bool procv=false)
  :Foo(name,weight,type),proc(procv){}
  Boo(const Boo &x):Foo(x),proc(x.proc){}
  int cena(){return Foo::cena() + proc*400; }
  friend ostream & operator <<(ostream &out , const Boo &x){
    return out<<x.name<<" "<<x.weight<<" "<<x.type<<" "<<x.proc;
  }
};
int main(){
  Boo a("vase",1,1,0);
  cout<<a;
  return 0;
}
