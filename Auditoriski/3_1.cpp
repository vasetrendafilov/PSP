#include "iostream"
#include "math.h"
#include "string"

using namespace std;
const int size = 100;
typedef int var;
struct Stack{
  var item[size];
  int top;
  void init();
  bool empty();
  bool full();
  void push(bool x);
  var pop();
  var peek();
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
var Stack::pop(){
  if(empty()){
    cout<<"Stack Underflow"<<endl;
    return 0;
  }
  return item[top--];
}
var Stack::peek(){
  if(empty()){
    cout<<"Stack Underflow"<<endl;
    return 0;
  }
  return item[top];
}
void dekvobin(int a){
  Stack x;
  x.init();
  while(a != 0){
    x.push(a%2);
    a/=2;
  }
  while(!x.empty()){
    cout<<x.pop();
  }
}
int main(){
  int a;
  cin>>a;
  dekvobin(a);
}
