#include "iostream"
#include "string"
using namespace std;

class Flight{
protected:
  string dist;
  int days;
  float price;
public:
  Flight(string distv="",float pricev=0,int daysv=0)
  :dist(distv),price(pricev),days(daysv){}
  Flight(const Flight &x)
  :dist(x.dist),price(x.price),days(x.days){}
  bool min(Flight &f){ return price < f.price;}
  float eu2mk(){ return (price*61.7); }
  void print(){
    cout<<dist<<" "<<days<<" "<<eu2mk()<<endl;
  }
};
class Foo{
protected:
  Flight *flights;
  int br;
  float fullprice;
public:
  Foo(Flight *flightsv =NULL , int brv=0):br(brv){
    flights = new Flight[br];
    fullprice = 0;
    for(int i=0;i<br;i++){
       fullprice += flightsv[i].eu2mk();
       flights[i] = flightsv[i];
     }
  }
  Foo(const Foo &x):br(x.br),fullprice(x.fullprice){
    flights = new Flight[br];
    for(int i=0;i<br;i++) flights[i] = x.flights[i];
  }
  Flight min(){
    int n=0;
    for(int i=1;i<br;i++)
      if ( !flights[n].min(flights[i])) n=i;
    return flights[n];
  }
  void nadpros(){
    for(int i=0;i<br;i++)
      if(flights[i].eu2mk() > fullprice/br) flights[i].print();
  }
};
int main(){
  Flight a[]={Flight("MK",100,1),Flight("UK",140,4),Flight("LI",123,9)};
  Foo b(a,3);
  b.nadpros();
  return 0;
}
