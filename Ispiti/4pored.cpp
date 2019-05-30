#include "iostream"
#include "string"
#include "cstring"
using namespace std;
class Zbor{
protected:
  string zbor;
  int n;
public:
  Zbor(string zborv="",int nv=0):zbor(zborv),n(nv){}
  Zbor(const Zbor &x):zbor(x.zbor),n(x.n){}
  virtual int length() = 0;
  virtual void print()=0;
  bool operator < (int n){ return (zbor.length()<n);}
};
class Imenka:public Zbor{
protected:
  int rod;
  bool pr;
public:
  Imenka(string zbor="",int n=0,int rodv=0,bool prv=false)
  :Zbor(zbor,n),rod(rodv),pr(prv){}
  int length(){
    int length = zbor.length();
    if(!pr) return length;
    if(zbor[length-1] == 'e' || zbor[length-1] == 'i' || zbor[length-1] == 'a') return length-1;
    else if(zbor.substr(length-3,3) == "nja" || zbor.substr(length-3,3) == "nje") return length-3;
  }
  void print(){
    cout<<"Zborot "<<zbor<<" e imenka i ima "<<length()<<" bukvi"<<endl;
  }
};
class Glagol:public Zbor{
protected:
  int vreme;
public:
  Glagol(string zbor="",int n=0,int vremev=0)
  :Zbor(zbor,n),vreme(vremev){}
  int length(){
    int length = zbor.length();
    if(vreme == 0 && zbor[length-1] == 'v') return length-1;
    else if(vreme == 0 && zbor.substr(length-3,3) == "vme") return length-3;
    if(vreme == 2 && zbor.substr(0,3) == "kje") return length-4;
  }
  void print(){
    cout<<"Zborot "<<zbor<<" e glagol i ima "<<length()<<" bukvi"<<endl;
  }
};
class Recenica{
protected:
  Zbor **zborovi;
  int br;
public:
  Recenica(Zbor **zboroviv=NULL,int brv=0):br(brv){
    zborovi = new Zbor*[br];
    for(int i=0;i<br;i++)
    zborovi[i] = zboroviv[i];
  }
  Recenica(const Recenica &x):br(x.br){
    zborovi = new Zbor*[br];
    for(int i=0;i<br;i++)
    zborovi[i] = x.zborovi[i];
  }
  ~Recenica(){
    for(int i=0;i<br;i++)
      delete zborovi[i];
    delete [] zborovi;  
  }
  void sort(){
    for(int i=0;i<br;i++)
        for(int j=0;j<i;j++)
          if(zborovi[i]->length() < zborovi[j]->length()){
            Zbor *temp;
            temp = zborovi[j];
            zborovi[j] = zborovi[i];
            zborovi[i] = temp;
          }
      for(int i=0;i<br;i++)
          zborovi[i]->print();
  }
};
int main(){
  Zbor *zborovi[5];
  zborovi[0] = new Imenka("fakulteti", 1, 0, 1);
  zborovi[1] = new Glagol("odevme", 2, 0);
  zborovi[2] = new Glagol("kje pishuvame", 3, 2);
  zborovi[3] = new Imenka("vreminja", 4, 2, 1);
  zborovi[4] = new Glagol("peam", 5, 1);
  Recenica r(zborovi, 5);
  r.sort();
return 0;
}
