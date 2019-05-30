#include "iostream"
#include "string"
#include "cstring"
using namespace std;

class Grade{
protected:
  string name;
  char *prezime;
  int ocena;
public:
  Grade(string namev="",char *prezimev =NULL,int ocenav=0)
  :name(namev),ocena(ocenav){
    prezime = new char[strlen(prezimev)+1];
    strcpy(prezime,prezimev);
  }
  virtual void print(){
    cout<<name<<" "<<prezime;
  }
  virtual int grade()=0;
};
class Xor:public Grade{
protected:
  bool redoven;
public:
  Xor(string name="",char *prezime=NULL,int ocena=0,bool redovenv=false)
  :Grade(name,prezime,ocena),redoven(redovenv){}
  Xor(const Xor &x):Grade(x),redoven(x.redoven){}
  virtual int grade(){
    return (ocena + redoven > 5)? 5:ocena +redoven;
  }
  virtual void print(){
    Grade::print();
    cout<<" Redoven: "<<((redoven)?"da ":"ne ")<<grade();
  }
};
class Foo: public Grade{
protected:
  int br;
public:
  Foo(string name = "",char *prezime=NULL,int ocena=0,int brv=0)
  :Grade(name,prezime,ocena),br(brv){}
  Foo(const Foo &x):Grade(x),br(x.br){}
  virtual int grade(){
    int temp = ocena + (br == 1) + (br > 1)*2;
    return (temp >5)?5:temp;
  }
  virtual void print(){
    Grade::print();
    cout<<" INstrimenti: "<<br<<" "<<grade();
  }
};
void max(Grade *niz[],int br){
  for(int i=0;i<br;i++)
    if(niz[i]->grade() == 1)
      niz[i]->print();
}
int main(){
  Grade *niz[10];
  char g[] = {'k','a','o','\0'};
  Foo a("vase",g,1,0),b("dsa",g,1,5);
  Xor c("asd",g,3,1);
  niz[0] = &a;
  niz[1] = &b;
  niz[2] = &c;
  max(niz,3);
  return 0;
}
