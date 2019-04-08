#include "iostream"
#include "string"
using namespace std;

typedef int var;
const int size = 50;
struct Stack{
  var item[size];
  int top;
  void init();
  void push(var x);
  var pop();
  var peek();
  bool empty();
  bool full();
};
void Stack::init(){top = -1;}
bool Stack::empty(){ return(top == -1); }
bool Stack::full(){ return(top == size - 1);}
void Stack::push(var x){
  if(full()){
    cout<<"Stack Overfolw"<<endl;
    return;
  }
  item[++top] = x;
}
var Stack::pop(){
  if(empty()){
    cout<<"Stack Underflow"<<endl;
    return 0;
  }
  return item[top--];
}
var Stack::peek(){
  return item[top];
}
struct Red{
  var item[size];
  var f,b;
  void init();
  void push(var x);
  var pop();
  var peek();
  bool empty();
  bool full();
};
void Red::init(){
  f=0;
  b=-1;
}
bool Red::empty(){return(b==-1);}
bool Red::full(){ return(b == size-1);}
void Red::push(var x){
  if(full()) return;
  item[++b]=x;
}
var Red::pop(){
  if(empty()) return 0;
  var temp = item[f];
  for (int i = f; i < b; i++) item[i] = item[i+1];
  b--;
  return temp;
}
var Red::peek(){
if(empty()) return 0;
return item[f];
}
void calc(Stack &m,Red &n){
  var temp = m.pop();
  n.push(temp);
  while (!m.empty())
    if(temp != m.peek()){
      temp = m.pop();
      n.push(temp);
    }else m.pop();


  while(!n.empty())
  cout<<n.pop()<<" ";
}
int main(){
  Stack m;
  Red n;
  m.init();
  n.init();
  int br,k;
  cin>>k;
  for (size_t i = 0; i < k; i++) {
    cin>>br;
    m.push(br);
  }
  calc(m,n);
  return 0;
}
