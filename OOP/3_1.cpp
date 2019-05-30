#include "iostream"
#include "string"

using namespace std;

class igrac{
protected:
  string ime, prezime;
  int igra;
public:
 igrac(string x="",string p="",int i=0):ime(x),prezime(p),igra(i){}
 igrac(const igrac &x):ime(x.ime),prezime(x.prezime),igra(x.igra){}
 friend ostream & operator << (ostream &out, const igrac &x);
};
ostream & operator << (ostream &out, const igrac &x){
  out<<x.ime<<" "<<x.prezime<<" "<<x.igra;
  return out;
}
class atp:public igrac{
private:
  int rang;
public:
  atp(string ime,string prezime,int igra,int r):igrac(ime,prezime,igra),rang(r){}
  atp(const atp &x):igrac(x){}
  friend ostream & operator << (ostream &out, const atp &x);
};
ostream & operator << (ostream &out, const atp &x){
  out<<x.ime<<" "<<x.prezime<<" "<<x.igra<<" "<<x.rang;
  return out;
}
int main(){
  atp a("vawes","sdad",1,20);
  igrac b("vasd","asdf",1);
  cout<<a<<endl<<b;
  return 0;
}
