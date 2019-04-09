#include "iostream"
#include "string"
using namespace std;

typedef int var;

struct Node{
  var item;
  Node *next,*prev;
};
struct List{
  int brel;
  Node *head,*tail;
  void init();
  void push(var x,bool back);
  void pop(bool back);
  void popel(Node *temp);
  void remove();
  void print();
};
void List::init(){ head = tail = NULL; brel = 0;}
void List::push(var x,bool back = false){
  Node *temp = new Node;
  temp->item = x;
  if(head == NULL){
    temp->next = temp->prev = temp;//tka
    head = tail = temp;
  }else if(back){
    temp->next = head;
    head->prev = temp;//tka
    head = temp;
    tail->next = head;
    head->prev = tail;//tak
  }else{
    tail->next = temp;
    temp->prev = tail;//tak
    tail=temp;
    tail->next = head;
    head->prev = tail;//tak
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
      head->next->prev = tail;//tak
      delete head;
      head = tail->next;
    }else{
      tail->prev->next = head;//ova celo
      head->prev = tail->prev;//
      delete tail;//
      tail = head->prev;//
    }brel--;
  }
}
void List::popel(Node *temp){
  if(head == temp)
      head = temp->next;
  if(tail == temp)
      tail = temp->prev;
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  delete temp;
  brel--;
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
