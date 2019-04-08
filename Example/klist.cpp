#include "iostream"
#include "string"
using namespace std;

typedef int var;

struct Node{
  var item;
  Node *link;
};

struct List{
  Node *head,*tail;
  void init();
  void push(var x,bool f);
  void pop(bool f);
  void remove();
  void print(bool f);
};
void List::init(){ head = tail = NULL; }
void List::push(var x,bool f = false){
  Node *temp = new Node;
  temp->item = x;
  if(head == NULL){
    temp->link = temp;
    head = tail = temp;
  }else if(f){
    temp->link = head;
    head = temp;
    tail->link = head;
  }else{
    tail->link = temp;
    tail = temp;
    tail->link = head;
  }
}
void List::pop(bool f=false){
  if(head == NULL)
    cout<<"Listata e prazna"<<endl;
  else if(head->link == NULL){
    delete head;
    head = NULL;
  }else if(f){
    Node *temp = head;
    head = head->link;
    delete temp;
  }else{
    Node *i,*temp;
    for(i = head ; i->link->link != NULL ; i=i->link);
     temp = i->link;
     i->link = NULL;
     delete temp;
  }
}
void List::remove(){
  while(head!=NULL) pop(true);
}
void List::print(bool f=false){
  for(Node *i = (f==true)?head:tail ;i!= head;i=i->link)
   cout<<i->item<<" ";
}
int main(){
  List a;
  a.init();
  a.push(10);
  a.push(5);
  a.push(3);
  a.print();
  return 0;
}
