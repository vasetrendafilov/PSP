#include "iostream"
#include "string"
using namespace std;

typedef char var;
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
void poli(Stack &m,string a){
  for (size_t i = 0; i < a.length(); i++) m.push(a[i]);
  for(int i = 0; !m.empty();i++)
    if(m.pop() != a[i]){
      cout<<"false"<<endl;
      return;
    }
  cout<<"true"<<endl;  
}
int main(){
  Stack s;
  s.init();
  string a;
  cin>>a;
  poli(s,a);
}
