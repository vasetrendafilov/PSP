#include "iostream"
#include "string"
using namespace std;

typedef int var;

struct Node{
  var item;
  Node *next,*prev;
};
struct List{
  int br;
  Node *head,*tail;
  void init();
  void push(var x,bool front);
  void pop(bool front);
  void remove();
  void print();
};
void List::init(){br=0; head = tail = NULL; }
void List::push(var x,bool front = false){
  Node *p = new Node;
  p->item = x;
  if(head == NULL){
    p->next = p->prev = p;
    head = tail = p;
  }
  if(front){
    p->next = head;
    head->prev = p;
    head = p;
    tail->next = head;
    head->prev = tail;
  }else{
    tail->next = p;
    p->prev = tail;
    tail=p;
    tail->next = head;
    head->prev = tail;
  }br++;
}
void List::pop(bool front = false){
  if(head == NULL) return;
  if(head->next == head){
    delete head;
    head = tail = NULL; br=0;
  }
  if(front){
    tail->next = head->next;
    head->next->prev = tail;
    delete head;
    head = tail->next;
  }else{
    tail->prev->next = head;
    head->prev = tail->prev;
    delete tail;
    tail = head ->prev;
  }br--;
}
void List::remove(){
  while(head!=NULL)pop(true);
}
void List::print(){
  Node *p=head;
  do{
    cout<<p->item<<" ";
    p=p->next;
  }while(p!=head);
}
int main(){
  List a;
  a.init();
  a.push(1);
  a.push(2);
  a.push(3);
  a.push(4);
  a.print();
  a.remove();
  return 0;
}
