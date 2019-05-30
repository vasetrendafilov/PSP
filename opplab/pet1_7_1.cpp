#include "iostream"
#include "string"
using namespace std;
class Song{
protected:
  string name,preformer;
  int nagradi,playes;
public:
  Song(string namev="",string pref="",int nag=0,int play=0)
  :name(namev),preformer(pref){
    nagradi = (nag>=0 && nag<=10)*nag;
    playes = (play>=0 && play <=20)*play;
  }
  Song(const Song &x)
  :name(x.name),preformer(x.preformer),nagradi(x.nagradi),playes(x.playes){}
  int popularity() const{
    return (nagradi + playes)/3;
  }
  friend ostream & operator << (ostream &out , const Song &x){
    return out<<x.name<<" "<<x.preformer<<" "<<x.popularity();
  }
};
class Foo:public Song{
protected:
  int br;
public:
  Foo(string name="",string pref="",int nag=0,int play=0,int brv=0)
  :Song(name,pref,nag,play),br(brv){}
  Foo(const Foo &x):Song(x),br(x.br){}
  int popularity(){
    return (Song::popularity()*3 + br)/4;
  }
  friend ostream & operator << (ostream &out ,  Foo &x){
    return out<<Song(x)<<" new "<<x.popularity();///very nice
  }
};
int main(){
  Foo a("vase","sad",10,5,20);
  cout<<a;
  return 0;
}
