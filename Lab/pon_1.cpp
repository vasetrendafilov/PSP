#include "iostream"
#include "string"
using namespace std;

typedef bool var;
const int size = 50;
struct Stack{
  var item[size];
  int top;
  void init();
  void push(var x);
  var pop();
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
void check(Stack &x,int br){
   while(!x.empty()){
     if(x.pop() != br%10){
       cout<<"ne se isti"<<endl;
       return;
     }
     br/=10;
   }
   cout<<"isti se"<<endl;

}
int main(){
  Stack m;
  m.init();
  int br,temp;
  cin>>br;
  temp = br;
  while(temp){
    m.push(temp%10);
    temp/=10;
  }
  check(m,br);
  return 0;
}
