#include "iostream"
#include "math.h"
#include "string"

using namespace std;
const int size = 100;
struct Stack{
  int items[size];
  int top;
  void init();
  bool isEmpty();
  bool isFull();
  int peek();
  int pop();
  void push(int x);
};
inline void Stack::init(){ top = -1; }
inline bool Stack::isEmpty(){ return (top == -1); }
inline bool Stack::isFull(){ return (top == size-1); }
void Stack::push(int x){
  if(isFull()){
    cout<<"Stack overflow"<<endl;
    return;
  }
  items[++top] = x;
}
int Stack::pop(){
  if(isEmpty()){
    cout<<"Stack underflow"<<endl;
    return 0;
  }
  return items[top--];
}
int Stack::peek(){
  if(isEmpty()){
    cout<<"Stack underflow"<<endl;
    return 0;
  }
  return items[top];
}
int main() {
  string a,b;
  cin>>a;
  b+=a;
  if(a==b)
  cout<<"sa";
   return 0;
}
