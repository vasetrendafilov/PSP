#include "iostream"
#include "string"
using namespace std;

typedef int var;

struct Node{
  var item;
  Node *next;
};

struct List{
  Node *head;
  void init();
  void push(var x,bool f);
  void pop(bool f);
  void remove();
  void print();
};
void List::init(){ head = NULL; }
void List::push(var x,bool f = false){
  Node *temp = new Node;
  temp->item = x;
  if(f){
    temp->next = head;
    head = temp;
  }else{
    temp->next = NULL;
    if(head == NULL) head = temp;
    else{
      Node *i;
      for(i = head ; i->next != NULL ; i = i->next);
      i->next = temp;
    }
  }
}
void List::pop(bool f=false){
  if(head == NULL)
    cout<<"Listata e prazna"<<endl;
  else if(head->next == NULL){
    delete head;
    head = NULL;
  }else if(f){
    Node *temp = head;
    head = head->next;
    delete temp;
  }else{
    Node *i,*temp;
    for(i = head ; i->next->next != NULL ; i=i->next);
     temp = i->next;
     i->next = NULL;
     delete temp;
  }
}
void List::remove(){
  while(head!=NULL) pop(true);
}
void List::print(){
  for(Node *i = head;i!= NULL;i=i->next)
   cout<<i->item<<" ";
}
int main(){
  List a;
  a.init();
  a.push(10);
  a.push(5);
  a.push(3,true);
  a.pop();
  a.print();
  a.remove();
  a.print();
  return 0;
}
