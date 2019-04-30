#include <iostream>
#include "string"
using namespace std;

class Fax{
private:
  int *kredits;
  int brPred,vkSem;
public:
  Fax(int br=0,int kred[]=NULL,int sem=0):brPred(br),vkSem(sem){
    kredits = new int[brPred];
    for(int i=0;i<brPred;i++)
      kredits[i] = kred[i];
  }
  void operator =(const Fax &x){
    brPred = x.brPred;
    vkSem = x.vkSem;
    delete [] kredits;
    kredits = new int[brPred];
    for(int i=0;i<brPred;i++)
      kredits[i] = x.kredits[i];
  }
  ~Fax(){
    delete [] kredits;
  }
  int func(){
    int n=0;
    for(int i=0;i<brPred;i++)
      if(kredits[i]==6)n++;
    return n;
  }
  int kredSum(){
    int temp=0;
    for(int i=0;i<brPred;i++)
      temp+=kredits[i];
    return temp/(brPred*vkSem);
  }
  friend ostream & operator << (ostream &out, const Fax &x);
  friend istream & operator >> (istream &in,  Fax &x);
};
ostream & operator << (ostream &out, const Fax &x)
{
    out<<"Broj semestri: "<<x.vkSem<<endl<<"Krediti po predmeti: \n";
    for(int i=0;i<x.brPred;i++)
      out<<x.kredits[i]<<" ";
    return out;
}

istream & operator >> (istream &in,  Fax &x)
{
    cout << "Br predmeti i semestri:\n";
    in >> x.brPred>>x.vkSem;
    cout << "Krediti po predmiti: \n";
    x.kredits = new int[x.brPred];
    for(int i=0;i<x.brPred;i++)
      in >> x.kredits[i];
    return in;
}
class Uni{
protected:
  Fax *fax;
  int br;
public:
  Uni(int x=0,Fax z[]=NULL):br(x){
    fax = new Fax[br];
    for(int i=0;i<br;i++)
      fax[i] = z[i];
  }
  void operator =(const Uni &x){
    br = x.br;
    delete [] fax;
    fax = new Fax[br];
    for(int i=0;i<br;i++)
      fax[i] = x.fax[i];
  }
  Fax naj(){
    Fax temp;// Fax temp = fax[0] ne zafrakava nesto
    temp = fax[0];
    for(int i=1;i<br;i++)
      if(temp.kredSum() < fax[i].kredSum())
        temp = fax[i];
    return temp;
  }
  friend ostream & operator << (ostream &out, const Uni &x);
};
ostream & operator <<(ostream &out,const Uni &x){
  for(int i=0;i<x.br;i++)
    out<<x.fax[i]<<endl;
  return out;
}
int main(){
  Fax a[2];
  for(int i=0;i<2;i++)
    cin>>a[i];
  Uni x(2,a),y;
  cout<<x.naj()<<endl<<endl;
  y = x;
  cout<<y<<endl;
  return 0;
}
