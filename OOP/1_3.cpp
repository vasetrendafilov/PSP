#include <iostream>
#include "string"

using namespace std;

class Flight{
private:
  string from,to;
  int id,pilotId;
public:
  Flight (int id = 0,int pilotId=0,string from="",string to=""){
    if(id<0) return;
    this->id = id;
    this->pilotId = pilotId;
    this->from =from;
    this->to = to;
  }
  void print(){
    cout<<id<<" : "<<from<<" , "<<to<<endl;
  }
  int getId(){ return pilotId; }
};
class Pilot{
private:
  string name;
  int id,salary;
public:
  Pilot (int id = 0,string name ="",int salary=0){
    this->id = id;
    this->name = name;
    this->salary = salary;
  }
  void print(){
    cout<<id<<" "<<name;
  }
  int getId(){return id;}
  int getSalary(){return salary;}
};
class Komp{
private:
  string name;
  int br;
  Flight flights[15];
public:
  Komp (string name,Flight flights[],int br){
    this->name = name;
    this->br = br;
    for(int i=0;i<br;i++)
    this->flights[i] = flights[i];
  }
  int check(int id){
    for(int i=0;i<br;i++)
      if(flights[i].getId() == id)
        return i;
    return -1;
  }
  void pay(Pilot pilots[],int n){
    int salary[n];
    for(int i=0;i<n;i++) salary[i]=0;
    for(int i=0;i<n;i++)
      if(check(pilots[i].getId())!= -1) salary[i]+=pilots[i].getSalary();
    for(int i=0;i<n;i++){
      pilots[i].print();
      cout<<" "<<salary[i]<<endl;
    }
  }
};
int main(){
  Pilot pilots[3] = {Pilot(1,"vase",100),Pilot(2,"bojan",123),Pilot(3,"nikolco",200)};
  Flight flights[4] = {Flight(1,1,"skopje","veles"),Flight(2,3,"dsa","ds"),Flight(3,2,"das","fs"),Flight(4,5,"negfe","fe")};
  Komp x("recani",flights,4);
  x.pay(pilots,3);

  return 0;
}
