#include "iostream"
#include "string"
using namespace std;

typedef int var;

struct Node{
  var item;
  Node *next;
};
struct List{
  int brel;
  Node *head,*tail;
  void init();
  void push(var x,bool back);
  void pop(bool back);
  void remove();
  void print();
};
void List::init(){ head = tail = NULL; brel = 0;}
void List::push(var x,bool back = false){
  Node *temp = new Node;
  temp->item = x;
  if(head == NULL){
    temp->next= temp;
    head = tail = temp;
  }else if(back){
    temp->next = head;
    head = temp;
    tail->next = head;
  }else{
    tail->next = temp;
    tail=temp;
    tail->next = head;
  }
  brel++;
}
void List::pop(bool back = false){
  if(head->next == head){
    delete head;
    head = tail = NULL;
  }
  if(head != NULL){
    if(back){
      tail->next = head->next;
      delete head;
      head = tail->next;
    }else{
      Node *temp;
      for(temp = head;temp->next != tail;temp=temp->next);
      temp->next = head;
      delete tail;
      tail = temp;
    }brel--;
  }
}
void List::remove(){
  while(head!=NULL) pop();
}
void List::print(){
  Node *temp = tail;
  if(head != NULL){
    do{
      cout<<temp->item<<" ";
      temp = temp->next;
    }while(temp != tail);
  }else
  cout<<"Listata e prazna"<<endl;
}

int main(){
  List a;
  a.init();
  a.push(10);
  a.push(5);
  a.push(2);
  a.push(4,true);
  a.print();
  a.remove();
  return 0;
}
