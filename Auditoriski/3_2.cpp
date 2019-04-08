#include "iostream"
#include "math.h"
#include "string"

using namespace std;
const int size = 100;
struct Stack{
  char item[size];
  int top;
  void init();
  bool empty();
  bool full();
  void push(bool x);
  char pop();
  char peek();
};
inline void Stack::init(){ top= -1; }
bool Stack::empty(){ return(top == -1); }
bool Stack::full(){ return(top == size-1); }
void Stack::push(bool x){
  if(full()){
    cout<<"Stack Overflow"<<endl;
    return;
  }
  item[++top]=x;
}
char Stack::pop(){
  if(empty()){
    cout<<"Stack Underflow"<<endl;
    return '';
  }
  return item[top--];
}
char Stack::pop(){
  if(empty()){
    cout<<"Stack Underflow"<<endl;
    return '';
  }
  return item[top];
}

int main(){
  string a;
  cin>>a;
  prov(a);
}
