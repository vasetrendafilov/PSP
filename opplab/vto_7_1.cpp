#include "iostream"
#include "string"
using namespace std;
class App{
protected:
  string name;
  int price,size,sold;
public:
  App(string namev="",int pricev = 0,int sizev=0,int soldv=0)
  :name(namev),price(pricev),size(sizev),sold(soldv){}
  App(const App &x)
  :name(x.name),price(x.price),size(x.size),sold(x.sold){}
  int zarabotka(){
    return price*sold/size;
  }
  App & operator ++(int){
    sold++;
    return *this;
  }
  friend ostream & operator <<(ostream &out,const App &x){
    return out<<x.name<<" "<<x.price<<" "<<x.size<<" "<<x.sold;
  }
};
class Android:public App{
protected: int version;
public:
  Android(string namev="",int pricev = 0,int sizev=0,int soldv=0,int versionv=0)
  :App(namev,pricev,sizev,soldv),version(versionv){}
  Android(const Android &x):App(x),version(x.version){}
  int zarabotka(){
    int temp = App::zarabotka();
    return (temp > 100)*(0.15*temp)+temp;
  }
  friend ostream & operator <<(ostream &out,const Android &x){
    return out<<x.name<<" "<<x.price<<" "<<x.size<<" "<<x.sold<<x.version;
  }
};
int main(){
  Android a("vase",1000,1,1,4);
  cout<<a.App::zarabotka();
  return 0;
}
