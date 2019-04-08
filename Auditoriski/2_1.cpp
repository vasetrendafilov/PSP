#include "iostream"
#include "math.h"
#include "string"

using namespace std;

struct Friend{
  string ime,date,zid;
  void print(){
    cout<<ime<<" "<<date<<" "<<zid<<endl;
  }
};

struct Acc {
  string ime,grad,date;
  int br;
  Friend prijatel[5000]; //friend; ne raboti vaka ako se najavi
  void print(){
    cout<<ime<<" "<<grad<<" "<<date<<" "<<br<<endl;
    for (int i = 0; i < br; i++) {
      prijatel[i].print();
    }
  }
  void change_name(string name){
    ime = name;
  }
  void change_date(string name){
    date = name;
  }
  void change_grad(string name){
    grad = name;
  }
  void add(Friend c) {
    if(br<5000){
    prijatel[br] = c;
    br+=1;
  }
  }
  void remove(string name) {
    for (int i = 0; i < br; i++) {
      if(prijatel[i].ime == name){
        for (size_t j = i; j < br; j++)
          prijatel[j] = prijatel[j+1];
        br--;
      }
    }
  }
  void rod(string datum){
    for (int i = 0; i < br; i++)
      if(prijatel[i].date == datum)
        prijatel[i].zid = "Happy birday!!!!!!";
  }
};
int main() {
   Acc a = {"Vase","Veles","10/01/2000",0};
   Friend b = {"dada","sad",""};
   Friend c = {"sssss","rrrr",""};
   a.add(c);
   a.add(b);
   //a.remove("sssss");
   a.rod("sad");
   a.print();


  return 0;
}
