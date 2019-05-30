#include "iostream"
#include "string"
using namespace std;

class Covek{
protected:
  string name,adress;
  int year;
public:
  Covek(string namev = "",int yearv=0,string adressv="")
  :name(namev),year(yearv),adress(adressv){}
  Covek(const Covek &x)
  :name(x.name),year(x.year),adress(x.adress){}
  virtual void vnesi(string namev = "", int yearv=0,string adressv="",string f="",int g=0){
    name = namev;
    year = yearv;
    adress = adressv;
  }
  virtual void print(){
    cout<<name<<" "<<year<<" "<<adress<<" ";
  }
  int getYear(){return year;}
  bool operator > (Covek &x){ return (this->year > x.year);}
};
class Kid:public Covek{
protected:
  string scholl;
  int grade;
public:
  Kid(string name="",int year=0,string adress="",string schollv="",int gradev=0)
  :Covek(name, year,adress),scholl(schollv),grade(gradev){}
  Kid(const Kid &x):Covek(x),scholl(x.scholl),grade(x.grade){}
  void vnesi(string namev = "", int yearv=0,string adressv="",string f="",int g=0){
    Covek::vnesi(namev,yearv,adressv);
    scholl = f;
    grade = g;
  }
  void print(){
    Covek::print();
    cout<<scholl<<" "<<grade<<endl;
  }
};
class Man:public Covek{
protected:
  string firm;
  int staz;
public:
  Man(string name="",int year=0,string adress="",string firmv="",int stazv=0)
  :Covek(name, year,adress),firm(firmv),staz(stazv){}
  Man(const Man &x):Covek(x),firm(x.firm),staz(x.staz){}
  void vnesi(string namev = "", int yearv=0,string adressv="",string f="",int g=0){
    Covek::vnesi(namev,yearv,adressv);
    firm = f;
    staz = g;
  }
  void print(){
    Covek::print();
    cout<<firm<<" "<<staz<<endl;
  }
};
class Semejstvo{
protected:
  Covek **nizz;
  int br;
public:
  Semejstvo(Covek **nizzv = NULL,int brv=0):br(brv){
    nizz = new Covek*[br];
    for(int i=0;i<br;i++)
      nizz[i] = nizzv[i];
  }
  Semejstvo(const Semejstvo &x):br(x.br){
    nizz = new Covek*[br];
    for(int i=0;i<br;i++)
      nizz[i] = x.nizz[i];
  }
  ~Semejstvo(){
    for(int i=0;i<br;i++)
      delete nizz[i];
    delete [] nizz;
  }
  void sortiraj(){
    for(int i=0;i<br;i++)
      for(int j=0;j<i;j++)
        if(*nizz[i] > *nizz[j]){
          Covek *temp;
          temp = nizz[i];
          nizz[i] = nizz[j];
          nizz[j] = temp;
        }
      for(int i=0;i<br;i++)
            nizz[i]->print();
  }
};
int main(){
  Covek *lugje[4];
  lugje[0] = new Kid();
  lugje[0]->vnesi("Toni", 2007, "Adresa 1", "Uchilishte 1", 3);
  lugje[1] = new Man();
  lugje[1]->vnesi("Ana", 1980, "Adresa 1", "Firma 1", 10);
  lugje[2] = new Kid();
  lugje[2]->vnesi("Marija", 2005, "Adresa 1", "Uchilishte 1", 5);
  lugje[3] = new Man ();
  lugje[3]->vnesi("Mitko", 1980, "Adresa 1", "Firma 2", 12);
  Semejstvo s(lugje, 4);
  s.sortiraj();
  return 0;
}
