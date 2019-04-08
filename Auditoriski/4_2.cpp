#include "iostream"
#include "string"

using namespace std;


typedef char var;
const int size = 100;

struct Red{
  var item[size];
  int first,last;
  void init();
  void push(var x);
  var pop();
  bool empty();
  bool full();
};

void Red::init(){
  first = 0;
  last = -1;
}
bool Red::empty(){ return (last == -1); }
bool Red::full(){ return (last == size-1); }
void Red::push(var x){
  if(full()){
    cout<<"Satack Overflow"<<endl;
    return;
  }
  item[++last] = x;
}
var Red::pop(){
  if(empty()){
    cout<<"Satack Underflow"<<endl;
    return 0;
  }
  var temp = item[first];
  for(int i = first; i < last ; i++)
    item[i] = item[i+1];
  last--;
  return temp;
}
struct Stack{
  var item[size];
  int top;
  void init();
  void push(var x);
  bool empty();
  bool full();
  var pop();
};
void Stack::init(){top=-1;}
bool Stack::empty(){return(top == -1);}
bool Stack::full(){return(top == size-1);}
void Stack::push(var x){
  if(full()){
    cout<<"polno e"<<endl;
    return;
  }
  item[++top]=x;
}
var Stack::pop(){
  if(empty()){
    cout<<"prazno"<<endl;
    return 0;
  }
  return item[top--];
}
void calc(Red &x,string a){
  int flag = 0;
  Stack s;
  s.init();
  for(int i=0;i<a.length();i++){
      if(a[i] == 'X') flag++;
      if(flag == 1) s.push(a[i]);
        x.push(a[i]);
      if(flag == 2){
        s.push('X');
        while(!s.empty())
        x.push(s.pop());
        flag++;
      }  
  }
  while (!x.empty())
  cout<<x.pop();
}
int main(){
  Red x;
  string a;
  x.init();
  cin>>a;
  calc(x,a);
}
