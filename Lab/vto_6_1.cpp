#include "iostream"
#include "string"
using namespace std;

class Stan{
private:
  int kat,br;
  int *sobi;
public:
  Stan(int brv = 0, int x[] = NULL , int katv = 0):br(brv),kat(katv){
    sobi = new int[br];
    for(int i=0;i<br;i++)
      sobi[i] = x[i];
  }
  ~Stan(){delete [] sobi;}
  void operator = (const Stan &x){
    kat = x.kat;
    br = x.br;
    delete [] sobi;
    sobi = new int[br];
    for(int i=0;i<br;i++)
      sobi[i] = x.sobi[i];
  }
  int price(){
    int temp = 0;
    for(int i=0;i<br;i++)
      temp += sobi[i];
    return temp;
  }
  friend ostream & operator <<(ostream &out , const Stan &x);
};
ostream & operator <<(ostream &out , const Stan &x){
  out<<"Kat: "<<x.kat<<endl;
  for(int i=0;i<x.br;i++)
    out<<x.sobi[i]<<" ";
  return out;
}
class Zgrada{
private:
  int br;
  Stan *stans;
public:
  Zgrada(int brv = 0,Stan x[] = NULL):br(brv){
    stans = new Stan[br];
    for(int i=0;i<br;i++)
      stans[i] = x[i];
  }
  ~Zgrada(){delete [] stans;}
  void operator = (const Zgrada &x){
    br = x.br;
    delete [] stans;
    stans = new Stan[br];
    for(int i=0;i<br;i++)
      stans[i] = x.stans[i];
  }
  Stan cheapest(){
    Stan temp;
    temp = stans[0];
    for(int i=1;i<br;i++)
      if(temp.price()>stans[i].price())
        temp = stans[i];
    return temp;
  }
};
int main(){
  int temp[] = {10,30,20},s[]={30,22,33};
  Stan a[2];
  a[0] = Stan(3,temp,1);
  a[1] = Stan(3,s,2);
  Zgrada f(2,a);
  cout<<f.cheapest()<<endl;
  return 0;
}
