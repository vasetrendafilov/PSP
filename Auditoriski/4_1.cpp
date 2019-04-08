#include "iostream"
#include "string"

using namespace std;


struct Person{
  string ime,prezime;
  bool lc,ps,vz;
};
const int size = 100;

struct Red{
  Person item[size];
  int first,last;
  void init();
  void push(Person x);
  Person pop();
  Person peek();
  bool empty();
  bool full();
};

void Red::init(){
  first = 0;
  last = -1;
}
bool Red::empty(){ return (last == -1); }
bool Red::empty(){ return (last == size-1); }
void Red::push(Person x){
  if(full()){
    cout<<"Satack Overflow"<<endl;
    return;
  }
  item[++last] = x;
}
Person Red::pop(){
  if(empty()){
    cout<<"Satack Underflow"<<endl;
    return {};
  }
  Person temp = item[first];
  for(int i = first; i < last ; i++)
    item[i] = item[i+1];
  last--;
  return temp;
}
Person Red::peek(){
  if(empty()){
    cout<<"Satack Underflow"<<endl;
    return {};
  }
  retrun item[first];
}
void usluzi(Person &lc,Person &ps, Person &vz){
  while (!lc.empty()) {
    Person temp = lc.pop();
    if(temp.ps == true)
      ps.push(temp);
    else if(temp.vs == true)
      ps.push(temp);  
  }






}
