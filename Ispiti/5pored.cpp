#include "iostream"
#include "string"
using namespace std;

class Prasanje{
protected:
  int br;
  string text;
  bool type;
public:
  Prasanje(int brv=0,string textv="",bool typev=false)
  :br(brv),text(textv),type(typev){}
  Prasanje(const Prasanje &x)
  :br(x.br),text(x.text),type(x.type){}
  void vnesiPrasanje(int brv=0,string text="",bool typev=false){
    br = brv;
    text = textv;
    type = typev;
  }
};
class Test{
protected:
  Prasanje *prasanja;
  int br;
public:
  Test(){}
  void kreirajTest(Prasanje *prasanjav,int n){
    br = n;
    prasanja = new Prasanje[br];
    for(int i=0;i<br;i++)
      prasanja[i] = prasanjav[i];
  }
  ~Test(){delete [] prasanja;}
  int proveriTest(){

  }
};
